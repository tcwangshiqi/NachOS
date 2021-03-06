// machine.h 
//	Data structures for simulating the execution of user programs
//	running on top of Nachos.
//
//	User programs are loaded into "mainMemory"; to Nachos,
//	this looks just like an array of bytes.  Of course, the Nachos
//	kernel is in memory too -- but as in most machines these days,
//	the kernel is loaded into a separate memory region from user
//	programs, and accesses to kernel memory are not translated or paged.
//
//	In Nachos, user programs are executed one instruction at a time, 
//	by the simulator.  Each memory reference is translated, checked
//	for errors, etc.
//
//  DO NOT CHANGE EXCEPT AS NOTED BELOW -- part of the machine emulation
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef MACHINE_H
#define MACHINE_H

#include "copyright.h"
#include "utility.h"
#include "translate.h"

// Definitions related to the size, and format of user memory

const int PageSize = 128; 		// set the page size equal to
					// the disk sector size, for simplicity

//
// You are allowed to change this value.
// Doing so will change the number of pages of physical memory
// available on the simulated machine.
//
const int NumPhysPages = 128;

const int MemorySize = (NumPhysPages * PageSize);
const int TLBSize = 4;			// if there is a TLB, make it small

enum ExceptionType { NoException,           // Everything ok!
		     SyscallException,      // A program executed a system call.
		     PageFaultException,    // No valid translation found
		     ReadOnlyException,     // Write attempted to page marked 
					    // "read-only"
		     BusErrorException,     // Translation resulted in an 
					    // invalid physical address
		     AddressErrorException, // Unaligned reference or one that
					    // was beyond the end of the
					    // address space
		     OverflowException,     // Integer overflow in add or sub.
		     IllegalInstrException, // Unimplemented or reserved instr.
		     
		     NumExceptionTypes
};

// User program CPU state.  The full set of MIPS registers, plus a few
// more because we need to be able to start/stop a user program between
// any two instructions (thus we need to keep track of things like load
// delay slots, etc.)

#define StackReg	29	// User's stack pointer
#define RetAddrReg	31	// Holds return address for procedure calls
#define NumGPRegs	32	// 32 general purpose registers on MIPS
#define HiReg		32	// Double register to hold multiply result
#define LoReg		33
#define PCReg		34	// Current program counter
#define NextPCReg	35	// Next program counter (for branch delay) 
#define PrevPCReg	36	// Previous program counter (for debugging)
#define LoadReg		37	// The register target of a delayed load.
#define LoadValueReg 	38	// The value to be loaded by a delayed load.
#define BadVAddrReg	39	// The failing virtual address on an exception

#define NumTotalRegs 	40

// The following class defines the simulated host workstation hardware, as 
// seen by user programs -- the CPU registers, main memory, etc.
// User programs shouldn't be able to tell that they are running on our 
// simulator or on the real hardware, except 
//	we don't support floating point instructions
//	the system call interface to Nachos is not the same as UNIX 
//	  (10 system calls in Nachos vs. 200 in UNIX!)
// If we were to implement more of the UNIX system calls, we ought to be
// able to run Nachos on top of Nachos!
//
// The procedures in this class are defined in machine.cc, mipssim.cc, and
// translate.cc.

class Instruction;
class Interrupt;

class Machine {
  public:
    Machine(bool debug);	// Initialize the simulation of the hardware
				// for running user programs
    ~Machine();			// De-allocate the data structures

// Routines callable by the Nachos kernel
    void Run();	 		// Run a user program

    int ReadRegister(int num);	// read the contents of a CPU register

    void WriteRegister(int num, int value);
				// store a value into a CPU regist%r
/oaDeta rtructurgs`accessible TG`the"Oeclgs ker.el -m main Im}iby and rbe// p@gg tabld/TLB.
//
?/ NoTm tHiu *all* colm}ni�euiO^ bepwaen the$tser�program ajd thu$kesnem 
// kR� In 4%rls of"th%3a data$svrtatupes (p|=s the!BPU ra�jstmrc!.�
 (  jhar *maifMemory;	I/�0pHysical!memory �o(store us�r Progscm
				?/ c/de ind"dAta,(whide gxa#uuing
�/ NKTE: tha ha�dAre$trcn{lation of vi�tual!addresqes`i~0the!usar x�odr`i
//(db p(ysical addrdsses (relative�vo the befin.kng ob "maenMehgry3)
/'(b`n be ckntrol,ed �y one �f:
//A traditional hmnear page table
/� "	a"softqre-|oaeed trclsla��of lo/ka{ide bsffer (tlb9 --$a ca`heof '/	  mcppinws of virtal(�age!3's to physican page #7s
/
// If "tlf" is NELL,�t(u�linear page tabla is used
o. If "tlb" is n�n-FULLl the N`chgs karnel hq reqpkns+blaf�r minaei.g
?/	�he"aonteots of the TLB*  Bwt the kmr�el cpn us` qny dat� s|rwct�re
//I)p wants (eg, 2egmelted pbgIno) f�rbhandling TLB cq#he mactes.
// 
// or({Ilp�icitY, both �he paWe�t`bl� q�inteb`ald thg t|B#pointer abeJo pujnic.  However, whalG0t(ere caj be m�ldXPdd$page tarles (�ne pu~ at�res7
// {taca, stored in Memmry), dherm is onhy nne VLFb(implemeoted an hardWApu!.�//`Thes ~he VLB!pinter {Ho]ld0e!co�siddr%d a� +rea��nly:< agthough!
?/$qhe$co,dmnts of t(� TLB are free$do BE modi~ied by tie!ke"ne| wofd�aze.

  �0Tr`nsnctkonEnxry *tl*;)	/7`this 0ninye2 snoeld b� conqidE�Ed 
			)// "zeiD-nnly"(tm Nachms k�oel c/ee

0  "trans�ationE|tzi�*pageabhg;
   (un3lened i�t`pagea"le�ize;

    b�.l Re�nMem(ind adDr, int(siz�l int* valUe-;   "�ool Wri|%Mem(i�t addr, )n cize< in4 vel5e!:J    			// �ae0or write ,0", or 4!bytes md virdu!l J		�-/ mamor�!hat addp(>� Za|urn FALSU 	f a$
	�	/. corrEct$rqjsla4qk~ ckul`n't be found.
  prarate��// RoupineS internal po th m�chioe simumA4ion - DK NOD cahl |hese directmY
 a "Smie lgdaye$IgAd(int naZ�Reg, ilt *extFal); !					/- Do a re~$ing del!ydd�kad"(moEi&ying a regi
 �  voit OneIlswr�cukon*I�structi�n!*i�atr); 	*$   				// Rgn Gne,x�rurucwinJ on !tseV�progrimN
 $  

H    ExceptionTyse T�ans,`tuhint 6irtEGdp, int* PHysItdr, int size,bo�l wvitijg-;
,   			/- Dr!�shete yn addre3s,�ald #hUck`fnr 
				'/ c|ignmen$� !Set t`e U{e anf dirty bitr in 
			K// the trancl`tio� DntrX,app�opraite�q-
"$ 			�/qnd0re�urn an exkepti�n code if tHe j				+/ tran{l`t)gl Coul`n7t0bd cn�pltd�d.
  `!void!RaiseExc�pt�on(Axce�TiooType which, ant cqdVAddr)+[			7/ Trap to�tle Nach/s kUr.olL `esa}s� nf0a
		// s}swmm c�ll o� otl%r�excepum/n.  
!`  v/it Dabueees();		//�inroke the useR pr�grgm d`bugge�
    void Duepstate((;	I// print th%�user C@U and�m`mory state�


/7 �nperna fauA stpuctures*
    int f%gister�[FQ�TotalRegs]; /. CPU vmgit�rs.!�p execqtljg usgr prwgraas

    bool%sileleStu0s		/o trox back`�ntO th% �ebuggEr iFder %aah		// sigula|ed0insvB5cTion   $in< sunwntilTime?		// dbop1"ac� in�o the debugger wpen�simulated				// time se�chms uhis value
    frieod0cmass 	�terr}pt:I	// ca�lc Delc�efLoae()!!�$
|;

extEzz boie Excepti�nHandmerGzcgptionT9pe which);
�		'+�Mntw9 point�into Nachos For(han`ling
			// u3mr"system c#mls"and�ex�eptamns
				/' Mefined in exceptioj.cc


// Routines borconvtr�ing Words$%nd Short Wgrdr po!and from�the// Ci}ulited machifm&s!vo�mat of little e�fiao.  If �h% �osd"machhne*// kr li�t,d undicn (�EC ajD Intel1, these enl!ux b%yng NOPs.
./
?/ W`at`iS storet yn@each!ffrlat:
//	ho�| byte ordes)no2
o/	   kernel da|a spruStuvaq
/   user regkctesc
/siMu,a`et eacji�d byte _rdEriog:
'/	$ !co&telt{ of Main�me]ory

unsignud mnt W/rdTHnst(unsig�ed�mn4 gmr�);
ufsigned(�(or| SiortVoHkstunsiWngd sho2pdshortword	
unsig~ud inu"Wor`ToMashi.a,vNsi�~ed int0wore-
nqignt 3hort K`osvt/Ma�hin}(unsaoned shorT snortwor$){

ctntif // MACHEGe_H
