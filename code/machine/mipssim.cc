/+ oipssim/cc -- �imulate(a MES`R2?3004$p2oc%rsorJ//
/�   Thiq code las been adapted fbmM IuqTeslout'q �ISSOE pack!ge.
/   Bype orfesio' iy lit0le-endi�n so&we ccn�`�8Compq`)b�e wmth
//` 0FEC RIKC sywtems.
o
//   TO&GMT`GIA�GD`,-`part of thE machije emulat)on
//�// C}0yright"(c! 1992-1;94 The Regents of thm Unk~ersity o& C!mmfk2nie�
// Ell righds reserved. !Sae`copYright.h fn� copYright nntace in� limitcti* *// of lkaba�)ty(and disc,Ai�er of warrajt�prO6isim�s�
//!Simulatqn fixes dmfe "y Peuer � Reisr�ez, c�a3s"of Sin\eb$�94/95 (Y+rk�
-'�I've no$!jeen"abde tn ues| �(is!exVensAvel{>// Ported t�!ne~ez"�erSion of Nacho�at Wat�s�oo by Rcott Graham hMar 9()>
k
#includE�"Copyrigh~/x"

Cincnude "debug>D,
#inclete "machinm.h"
#)nsludu &mips�io*h"
#inclqdm""Mcin.`"
st%tic!void Mult(ind$a. int`b, bo�m`s)gnedARyth, in|* hiPt�< �jt* loPur);

/� Th5 folmkw��g clasr ddfinec a. i.s�buct�on,!zepr}sgntEd il roth
/?(	u.dec�ee$ b)nary form
//  �   dackted do kdent�f;
$/	$  `o`ezition to do
/o	   !registdrs��o act on�//)    iox imMefiate op%:anf vulud

class`�jstrucpion �` publyc:    �oiD!DecgdM();	// d$b/`e`the bijari repreqenta|in$o� |he ansts5cti/n

  $ ubsign�d )nt fa,5D� /' bhnarylsepresgftat�on of |he$)nstr|ctio�	
  �`c�ar m`Aode3  $  /+ Dypeof instvqgtion.  Uhi3 iq LO\ the same as the0  `	� �! �// opcode viel$`from phe -n{tr5c4ion; see defs in �ipq>n
    ah`r ra, rt, r�; / Three regis4Eps from i.stc}cti�n.
�   �ld extra+    *(p_/ IameDi`t�"/r target or siamt fieLd or ogfset�
   0          `    � -/ Immddietes  re rignmexvevdel.*;

-/m-----,-----)?-----=<---��)-=---=----=�-,%---------=---------)=----m
// M�bhine0:Sun
;/ Slmtlape thu Gxmbudion of$a use2-dEvel program nn NaCjos.
�;	Called bY ehe kernel hen thq �rogram start� ep; nevdr ret%sns.�//
/'	Th�s rout9na is re-efrra�t, in that ih Ccn0be cal�ed �ul�iphe
//	uimes conburrejdly =- one for each th�e!d �xfcuting`qsar code>
/�	---)--%-=-,,--------------------,--------/------�--,------m-m----(---�
void
Makhm�e>:�n8)
{
 !  �nstsubtion �instr = newInstrUcd�nn;  //`s6gragi fo2 deCoded hfs4ructi�j

   �v (gebugm?HsEnajled('m'�) {
  "  � !cout`<< "Stazting program in t`Read: "$<| seRnel=>Cqrzmn|ThbeqDm>getNa=e();
)go�t �< ",4!t time:("&< kdrnel->stats->ugpa|Tic+s`<< "Ln";
0   |
0 � kerjem->indtr�upt->setstatashUsevMode*�
    fo� �3;( {       !Onei(rtructin:ijsdr);
	kebjel->ynterruqt�>OnwTkcK();
	�f (sinwleStep &2 (0wnntilTio�!=(ker~dl->stat3-<tot!h�icoS))
I  D}�ugger():
$  !}
}

/&---------,-----%-�--m=-,----------+,8-%------�,-%--,----)-=--�---/�//#PypeUoReg// 	Retrieve(4(� r��xst$r # �mFejred |o �n an InsTructign."
/----=-----�------�-----/=----�-)==-----------<)-!-----,--/-)--%------

3�Adic i.t Tx�eToReg(Re�T}pg deg( 	nstrUctinn +i.str){
2�  s�iuch (reg! {
      casu$RS:
�retuzn"instrm4~S;
�!    case RT:
	return inst�=~r4;�! 0   case R@:
	retWrn(instr->r&;      ka{e GXDRA;
	retuzn inspr->ext2�
   #  le�au,t:
	r�tu2< -0;
    }
}�
?/-�--(m--%--------------,--�-----%--�-----------m-----=--,---)---,-./ Ma�hine::OndI�sTsuction
/' 	Execute one ilsTrecuion broe c tser/lmve� Xro'rah
//// 	Iv uheRe is any kind of�excettion oR hftebrtpt,`we invoke the"//	exce`Tmon h`~eler,0and!whEn it`re�uvn�,`7e aeturn to Rtn,), which
.�	sihl bd-invkke!Es yb i loop*! This allows`ec�4m
ore-starv*�he instructi{o wxecttik from(the0begin�xnG, �n
�/	c!se anu oT o}r`staue"has c`anged.  O~ a syscalL,
�/ 	the O softwave!mus40)ncrgme�t the PC so�ex�cu4�on becIn�//!)a�"Tie�instruatik� iomEdiata|y(adte2 tie sySsall. ?/./	This�2outin% js re-mntrant, IJ thct mt can de(calleD mult)8le
//	ti�gs$cofcurrently --0oNe for ea#h txrgad executNg }ser co�e.
�/	We`get`rg-enTranc} �y ne6er caghing any eat` -- 7e alwAys0r�-starv tHe
//	simulapIon �rom scratcX�daci0time we ape!called (or!adter tsAqqing
-/	bach uo t`E$L`chOc`k!2nel kn an exceptmol or i��erru0v!,  md we alweys
//	s|obe all data jick to tie mqchine!ragi{tdrz and }emoby jEf�r%
//	leAvang." THir alloS�the0NacH�s kernel tn contrl�oer `ejavior-/	cy cojtrolljn' uhe c�n\mlt3 oa memgry, 4he translatioN table,
?	ynd the$2egister set.
//-------)�---------------,---/----------�-�---,------=--=-%---------

void
Machinu::On�Instr}sti�f(�fsdrucv)on$*instr)
{
!mfdef$SIM_IX
    inu by4e?  0    // descbib%d in Kane f�r MWL<LWR,.*.
#endIf

�!$ ijt rav;
    inT FextLoed�ag$=  ; 
�!  ynT NwxtHoaeVelu%`= 0;#	�(r�crd0delq�ed`lad opesatin,�to a0pl�
)	// hn phe �uture
  0 // Fetkh instR5ction�
!  !if0*)REedMem(Reeisturr[PCReg�, 4� &r g)9
	�etur;			// excepteon(gacutred
    iostr>vc|ue = scw;
    ynstrm>Decode)�

    mf h$5bug->I{KNe"lcd(7m')9 {
    �"  struct OpStrin' 
st� = 6npStrings[i>str->opAode]{
Ia(aR buF[80]3
*  (  (�ASSMRU,instr/>kpGoee <;0EaxOp#gde);
 0  0   bout << "At`PB = " << reeis�err[PCBe%];X	sprintf(btf,$cTr-,fgrm`t,!T�peToBmg(str/>crgs[0]l instr!-
	$  ` TypeT�Zag(str-�argsZ1]. ij�4r), T}peToRgg({trm?argS[�]� �ostr)!;
     !  cout << 2^V" << buf <<$"\.";
�   }
   $
)  !// A�mputg ne|t pc,(but dgn'u instal, yn cqse phere's an abror jr brqnch.
 $  inr pCAfper � s�gisturs[NexdPCReg] k 0;
 �  int sum, dIfv, tm`,�va|ue�
    uncigjmd inT rS ~t,$iom;�
 8� ?/0ExecU4e th�`inspruation (cf. Ka�e's0booi(    switc( (instr->oPCnde) {"	
   !  cqqu OPNADD:
	sum = recm{tdrs[instr=�rs] + reom{ter3[ins4s->rt];
iv (!((regiSteRy[in3vf->rc] ^ rmgkste2f[i�rtr->rt])(& IGN]BIt)"&&
	 !  (	rewisve2s[Ilstv�>s] ^�sum) & WIG^�BIT() {
	 $� RaireUzceqtio�(Ntevflow�xceptino, 0)?
	$ ``ra}qvn{�}
p%'iStersZil�tr-�r�U  sum;
	brgAk;
	
    � casm OPADDI:
Y�Um(=!regirue2s[in2tr~rs] k iNq4s-.e8tva;
	ig (!(regist�rS[ins|r-<rs]  inst"->extra) & SIG��BYT)`&&
)  0 ((instr-�Extra \*sum) &�SIFN�BIT+%�{JY    Rai{%E8cEptiob(ObebflowAxceptioN, 0+
	`   rgTurn;
	}	registarsinsvr->rt] <$sum;
	bpeak;
	
      cAso0OP_A DI�:	Vegys4epq[ho3tz-�rd] = rew�sderS[AnstR->s] * i~str-:%xtsa;*)brdak?*	
  !  4ccwe OP_QD@:
	registezs[inst�->vl]�- 2egipters{instr->ssY # reGisters[hnstr.rp_;*	break;
	*@    $uase OP_!NFz
pecisters[i>s�z->rd]$= reg�cuevsinstz,rs] & vegic|evw[i~str-�rd];
	braak;

      case(OP_ANDI;
registersSinst�,>rtU = r%gister3[instr-rrY"&((instrm>extrc �0xFfff);
	Break;
	
$     `gse`�P_BGQ:
	)V (registers[inqtr>rsM /= regi{ve�sRinsvr->rt]�
)   (qcAftev(= vegi�t�bs[NextPCreg] + nd�<UoAdtrhinsTr->exvra){
	bzea{3
	
 H $  sasg$OP_BW�QN:
	�uGxuers�R�#] =!registesr[NexpPcReg] +$4;8    �care OPOBGEZ:
ig"(!(rggister�[)o�tr-<rw] & CIGO�BT))
( !p#Afder = regiqters[JextCZAg]0+�IbdexTo@ddr(anst�->exura);	break;	J     0ca{% NP_BGT[�
	i$!(regatars[ins4r->rs0> 0<
	 !0�pcAdter�=`re'is|%rs[NextRCreg] K Inde|U~Ad�r inzpr->�xtza);
Ibreak;
	      case OP_BHEZ:
	yn (regIqter{[knstr/>rs\`<= 0)
�    rcAfTer ? regis�Erw[ngxtPCBeg] � HdexVOAdfr�insdr,gxtra)�
	bpe`k;
	     ,ccsm�OPOBLTZAL:
	regys|ers[V1] � registUrSKNehuPCFe�](+!4;
     `casm NP_�LTZ:
If$0regis�ers[i��tr->rs] &"SIGN_BHT)
I   !pcEftez = segis4er3YNex4PReg] + IndeyToAgdR(instr->ehtra);
	�reak:
	 ` "  c�sm OPOBNE:
�iF (peeisuers[ins|p-�s 1=`re�i{ters[inStr-~rt]!	  ! pcAbta2`= rewi�|ers[NextPCZeg] + I~dexPoAldr8instr-?exur�);�iBreak;
 `    gase MP_DIV
	if (�egisveRs[ins|v/>b~](>5 $) {
	   !regkst%rsSLoReg]$=�4;
	!   regiqtrr[HhReg] 9 4;
	} elsg0{
   $regis�ecc[xnREg]`="�ragis|ars[iFsr-:xs]  registerS[instr=>rt];
	  $ registg�s[HiRegY = rega�ters[insur->rs] %�registe2s[instr->rt};
	y
�break;
	
@  !  caSe2OP_DIVU:	  	  rs = (unsiGned )~t9 RufIwturs[instr%�rc];
	 �pt = un7Ig~ed ynt) �dgisters[ynwpr->rt];
	  ic`(rT �� 0) {
      vegistErs[LoRag] 9 0;Z	     $recisturs�H�Veg] =�0;	  } else`{	$   0 pkx } r{ /�rt:�	 !  " pegist�bs[LoVag] = (ift) t-p;*	 `   `tmp = r� %"rd+
      regm3terq[HiR�g] =�,in|+ ump;
	  =
 bbruak;
	
 �    ca{e �P_JAH:
�eglsteps[Z31Y!= regmqters[NextPAReg] +�4;
      c!se OP_j
	P#Afteb =!(`cIfter & 8hf0001) | INdexT/@�dr(instr/>extra);
	braak;
  ` � case �T_�ALR�J	^cgi3t%Rs_inrtRm>rd]=(regi{TersNeXtPCRe/U + 4; (    �a�i MP_JR:J	bc@fter = regispers�inrtr->zs];	breAk;
	
  `  $cas�$�@_LB:"�  %c`su Op_�BU:
	t]p = registers[in3trm>rs]$k instr->ehl2a?
�if (!ReadMem |mp, 9, vc,5e))
	  0 seTurn;

if�	(6alUe $ 4x0) && (ilstr->opCo�e ==�P_mB)�
	  �"valwe |= 0xnv&�fg00;
	e|se	   �value &= 0xnf;
	nuhtLoadReg = mnstr->r�?
Inext\OadRalue = t`lug;�r2eak;
	
      case OP^LL:
 �  0 c�we oP_LHU:	  �	t�p ? rewist�rs[ans4rl�Rs]"+ instr->expra
	if (tmp!� 0819${
I $ (RykseE��uptIon(AdfrgssArrkr�xcuppi/n, tm0;;
	0`  re4uro;
	}	if �!Rea`Me�(vop,!2, &ralua)+
 ! �zeturn;

	�f!8(velue& 0x8010) && (in{pr/.�pCde =�$OP_@H))
 !  ta�te |= 0Xjfff 000;
dls
� ( $valWe &< 0pgfff+
	nmxd\o`�Reg = il3tb-?b~;
	next\oadValue = valee�
breai;
      i
    ( c!se �P_LUM:	DEBUG<dbgKa`h- "Executinf: LUI r" << instbm>�t 4<�", " �< insts->ept2a)3
	�egis0ers�instp->rtU$< inrtr->extra0<< 1>;
	bru`++

!     cese OP_D�:*	dmp = pefiste�s�iFstr->Rs] #hinsTr->exTpa;
	if (t�t$!0x3+ {
	 (  R`iseExcdption,AddrusSErro�Excettio., tmp);
	    returo;	�
	if (!RaadIe�(tmp(!4, &value))�    veturn;
	ne|f�oadRu�"= anstr-:r��
nextLoadValqg =8valve;	Br%ak?J   `)J   !(0case GT_LWL:	 �
ump`= Pegistgzs[instr,>ssm ;(In�tr->extvc8NJ#ic`ef [	�^MH
	// Dhe onlyddi~fesen�e between`this bodd0cnd the BIG ENDIAF cfe.   $    // Is!t(at dhe ealEe� c`hl as�gu�ranteed cn!el�qned acce�s aS �t
! �     // shoeLd be (Oife's booi iudes th� �qct t`at all memory aaces{
  d  ! (// are `mne using aligne`"�oads - w(at the�instpuctiOn a�kw fos
((      / is e abbipra2i)(Thh3!yg!tj% ho,e!turose gf HV �jd LW etc.
 ! " �  // Then the {witch u3es  3 -��tur(&(0x2)  )nsTeaf"og8tmp & 0x3)

 ``(    fswe =(tmp &80x3;
 ( 0 "  // FEB�W(#P�, 2Addr �x%P\n",tm�-f{te);

$    ( �f (!Rea$Mem(tmp	bqte. 4.$&v!ltei�
  $    `�   rutqrN;
#dlse
	/ ReadMem"asst%es`aLm 0 byte raq�ests tve$alignmD on an �vdf 
	#+`vord �ound!ry.  Also�(�he litdl� g~d)an/b)g endia~ {waP {ode(woule
  0 0   //!fai� (I thil{) If the o�Hmr �q[dS arg eve� %xe�chsed.
	A�RERT)(|mp�f 0x3	 =900!;! 
�if (!recdMemtmp, 4l &`aluu)�	�   �eturn;
#enfif

	ib (regiquers[\oadRag| =- yl2tr-<bt)
	   `next�oadW!lua 5 xe�is5essSX�adv�lueReg];
	else
4   nax$LocdValue = regi3tgrs�insTr->s4]?
#igde&�SIM_�	H
	sw=tcH"(3 ��fyte)�
!e8se�	swi@ch (tmP & 0x19
#qnlyf
	! {
�  c!se 1z
    ng�4HOad�alue = wil}e;
	� 0$break;*! C!se 1:
	    lextL�edV�lue�- (nextLoad�a�uM(&$08nf��| hvaluE$<< 8	;
	 � �break�
	( �ase 2:
	�  "nextL�adVI,Ue = (fEhtLnadValuf & 18gFfb) |h(vanue �4 16);
�d   bseak;
	! aasd`7:
�0   nextLo`�V`lq% = (nmxtHoe�VAlue & 0xgf'f��) |"(vaLut ,< 2d);
	"  breaj=
}
	ne8uNoadReg = i��t26vt;
br�ak;
$     	��    ��aye0Op_MWR2
	ump!= regastdrS[instr->r3] + ijstr->extra:

"}dddg S	M^NAX
 $!     // Phm �nmy tIffercnce betwedn this code A~d |he BIgaE^DIAN kode
    $   // is t�at the RdauO�m"call is guaranteel an!`liged( ccars `s it
 �   �  ./`sxould%b� ��cne's fook hides �h% fabt th`T aLn�memory �ca%ss"$  $   �+ arg don% using aligned lo`ds - wht thl(instruct)on �ks 
   ! $� '/ d�r is"a`Arbitzqry) THis ic the wiole `qppose of LGL and LWR upC.
   &   /' Ti%N uhe cwidch ures! 3 -$(tgy$& 0x3/  instea`$mf0(�m�& 0x;)
 @   b�*bype 9 dmp � 0x3;
   0 !  // DEBTF('P', 
Idl�(0x%Xn".tm�-byte)+
  2"$   �f�$!eatMem*tmp-bite. 4, 'v`lue))� 0     "0   r�ttr�;
#else	/. ReaeOem assume{ all!4 byte requestq abe0A$ignad on ao Eve~1
	/- opt bnUfd�ry.  Also,�th% l	ttnE&el�hQn'big$e~`ian swap code woulD
  ( !0  // bcid$(I think9 if tha opher caoes arE ovmp exdb�isef.
	ASSEZT((tm` & 0x3) }= �):  
	if (!eamMem(tmp- 4 6vahue))
)    ~%turn;#endIf

	af (�EgiqteqsYLn!tZug]`== ynstr-��d)�	�   nextLoadTalue } 3Egistess[LoadValuqReg];
	elsE
 0! Nexp�oadV`lue = rh'istgrs[inqtr>rt]{

#ig$gr!SIM_FIX
	swipch (#!- �yve)0celr%
	swatch (�m4 &!0x3)
#gndif	  {
	  cqse �	  ` nextoaDVAlue = nextLoalVal5g & 0yfFfvgF00! |
)h(ralue1>>(2	 & 8xff)9
	 � �brmak+	  case 1:
	p " lextLOadValue!= (nextLkaDvAluw & 0x�vvf0800) T
	Y�valuE">> 1i & 08ffff){
	    bre!k;
	  case 2:
	    nextLoadVal�e =  nex�iadValue &"0xff000021)
		} ()vi�ed >"8) & 0xgcffff(�
	  $ break3
	$ c`sd 3:J	 !(�~extHgaDValue = vqlueI  $ bpeak;
	}
	nExtNmqdRef0= in�tr->r�;
	bp%ak;
 "  	
     `case KQ_M�HI:
	r%gisters[ins|p-~rd] = �%gip4mrsYJiReg];
�btaak;

 !    caru0OP_]VLO:*	r�giste2q[in{vr->st] = ragisters[HmRe'�;
��gak;
	   �� casg OP_MTHI:
	registers[HiReg] = registers[instr->rs];
	break;
	
      case OP_MTLO:
	registers[LoReg] = registers[instr->rs];
	break;
	
      case OP_MULT:
	Mult(registers[instr->rs], registers[instr->rt], TRUE,
	     &registers[HiReg], &registers[LoReg]);
	break;
	
      case OP_MULTU:
	Mult(registers[instr->rs], registers[instr->rt], FALSE,
	     &registers[HiReg], &registers[LoReg]);
	break;
	
      case OP_NOR:
	registers[instr->rd] = ~(registers[instr->rs] | registers[instr->rt]);
	break;
	
      case OP_OR:
	registers[instr->rd] = registers[instr->rs] | registers[instr->rt];
	break;
	
      case OP_ORI:
	registers[instr->rt] = registers[instr->rs] | (instr->extra & 0xffff);
	break;
	
      case OP_SB:
	if (!WriteMem((unsigned) 
		(registers[instr->rs] + instr->extra), 1, registers[instr->rt]))
	    return;
	break;
	
      case OP_SH:
	if (!WriteMem((unsigned) 
		(registers[instr->rs] + instr->extra), 2, registers[instr->rt]))
	    return;
	break;
	
      case OP_SLL:
	registers[instr->rd] = registers[instr->rt] << instr->extra;
	break;
	
      case OP_SLLV:
	registers[instr->rd] = registers[instr->rt] <<
	    (registers[instr->rs] & 0x1f);
	break;
	
      case OP_SLT:
	if (registers[instr->rs] < registers[instr->rt])
	    registers[instr->rd] = 1;
	else
	    registers[instr->rd] = 0;
	break;
	
      case OP_SLTI:
	if (registers[instr->rs] < instr->extra)
	    registers[instr->rt] = 1;
	else
	    registers[instr->rt] = 0;
	break;
	
      case OP_SLTIU:	  
	rs = registers[instr->rs];
	imm = instr->extra;
	if (rs < imm)
	    registers[instr->rt] = 1;
	else
	    registers[instr->rt] = 0;
	break;
      	
      case OP_SLTU:	  
	rs = registers[instr->rs];
	rt = registers[instr->rt];
	if (rs < rt)
	    registers[instr->rd] = 1;
	else
	    registers[instr->rd] = 0;
	break;
      	
      case OP_SRA:
	registers[instr->rd] = registers[instr->rt] >> instr->extra;
	break;
	
      case OP_SRAV:
	registers[instr->rd] = registers[instr->rt] >>
	    (registers[instr->rs] & 0x1f);
	break;
	
      case OP_SRL:
	tmp = registers[instr->rt];
	tmp >>= instr->extra;
	registers[instr->rd] = tmp;
	break;
	
      case OP_SRLV:
	tmp = registers[instr->rt];
	tmp >>= (registers[instr->rs] & 0x1f);
	registers[instr->rd] = tmp;
	break;
	
      case OP_SUB:	  
	diff = registers[instr->rs] - registers[instr->rt];
	if (((registers[instr->rs] ^ registers[instr->rt]) & SIGN_BIT) &&
	    ((registers[instr->rs] ^ diff) & SIGN_BIT)) {
	    RaiseException(OverflowException, 0);
	    return;
	}
	registers[instr->rd] = diff;
	break;
      	
      case OP_SUBU:
	registers[instr->rd] = registers[instr->rs] - registers[instr->rt];
	break;
	
      case OP_SW:
	if (!WriteMem((unsigned) 
		(registers[instr->rs] + instr->extra), 4, registers[instr->rt]))
	    return;
	break;
	
      case OP_SWL:	  
	tmp = registers[instr->rs] + instr->extra;

#ifdef SIM_FIX
        // The only difference between this code and the BIG ENDIAN code
        // is that the ReadMem call is guaranteed an aligned access as it
        // should be (Kane's book hides the fact that all memory access
        // are done using aligned loads - what the instruction asks for
        // is a arbitrary) This is the whole purpose of LWL and LWR etc.

        byte = tmp & 0x3;
        // DEBUG('P', "Addr 0x%X\n",tmp-byte);
        if (!ReadMem(tmp-byte, 4, &value))
            return;

        // DEBUG('P', "Value 0x%X\n",value);
#else

	// The little endian/big endian swap code would
        // fail (I think) if the other cases are ever exercised.
	ASSERT((tmp & 0x3) == 0);  

	if (!ReadMem((tmp & ~0x3), 4, &value))
	    return;
#endif

#ifdef SIM_FIX
	switch( 3 - byte )
#else
	  switch (tmp & 0x3) 
#endif // SIM_FIX
	    {
	  case 0:
	    value = registers[instr->rt];
	    break;
	  case 1:
	    value = (value & 0xff000000) | ((registers[instr->rt] >> 8) &
					    0xffffff);
	    break;
	  case 2:
	    value = (value & 0xffff0000) | ((registers[instr->rt] >> 16) &
					    0xffff);
	    break;
	  case 3:
	    value = (value & 0xffffff00) | ((registers[instr->rt] >> 24) &
					    0xff);
	    break;
	}
#ifndef SIM_FIX
        if (!WriteMem((tmp & ~0x3), 4, value))
            return;
#else
        // DEBUG('P', "Value 0x%X\n",value);

        if (!WriteMem((tmp - byte), 4, value))
            return;
#endif // SIM_FIX
	break;
    	
      case OP_SWR:	  
	tmp = registers[instr->rs] + instr->extra;

#ifndef SIM_FIX
        // The little endian/big endian swap code would
        // fail (I think) if the other cases are ever exercised.
        ASSERT((tmp & 0x3) == 0);  

        if (!ReadMem((tmp & ~0x3), 4, &value))
            return;
#else
        // The only difference between this code and the BIG ENDIAN code
        // is that the ReadMem call is guaranteed an aligned access as 
        // it should be (Kane's book hides the fact that all memory 
        // access are done using aligned loads - what the instruction 
        // asks for is a arbitrary) This is the whole purpose of LWL 
        // and LWR etc.

        byte = tmp & 0x3;
        // DEBUG('P', "Addr 0x%X\n",tmp-byte);

        if (!ReadMem(tmp-byte, 4, &value))
            return;
        // DEBUG('P', "Value 0x%X\n",value);
#endif // SIM_FIX

#ifndef SIM_FIX
        switch (tmp & 0x3) 
#else
	  switch( 3 - byte ) 
#endif // SIM_FIX
	    {
	    case 0:
	    value = (value & 0xffffff) | (registers[instr->rt] << 24);
	    break;
	  case 1:
	    value = (value & 0xffff) | (registers[instr->rt] << 16);
	    break;
	  case 2:
	    value = (value & 0xff) | (registers[instr->rt] << 8);
	    break;
	  case 3:
	    value = registers[instr->rt];
	    break;
	}

#ifndef SIM_FIX
        if (!WriteMem((tmp & ~0x3), 4, value))
            return;
#else
        // DEBUG('P', "Value 0x%X\n",value);

        if (!WriteMem((tmp - byte), 4, value))
            return;
#endif // SIM_FIX


	break;
    	
      case OP_SYSCALL:
	RaiseException(SyscallException, 0);
	return; 
	
      case OP_XOR:
	registers[instr->rd] = registers[instr->rs] ^ registers[instr->rt];
	break;
	
      case OP_XORI:
	registers[instr->rt] = registers[instr->rs] ^ (instr->extra & 0xffff);
	break;
	
      case OP_RES:
      case OP_UNIMP:
	RaiseException(IllegalInstrException, 0);
	return;
	
      default:
	ASSERT(FALSE);
    }
    
    // Now we have successfully executed the instruction.
    
    // Do any delayed load operation
    DelayedLoad(nextLoadReg, nextLoadValue);
    
    // Advance program counters.
    registers[PrevPCReg] = registers[PCReg];	// for debugging, in case we
						// are jumping into lala-land
    registers[PCReg] = registers[NextPCReg];
    registers[NextPCReg] = pcAfter;
}

//----------------------------------------------------------------------
// Machine::DelayedLoad
// 	Simulate effects of a delayed load.
//
// 	NOTE -- RaiseException/CheckInterrupts must also call DelayedLoad,
//	since any delayed load must get applied before we trap to the kernel.
//----------------------------------------------------------------------

void
Machine::DelayedLoad(int nextReg, int nextValue)
{
    registers[registers[LoadReg]] = registers[LoadValueReg];
    registers[LoadReg] = nextReg;
    registers[LoadValueReg] = nextValue;
    registers[0] = 0; 	// and always make sure R0 stays zero.
}

//----------------------------------------------------------------------
// Instruction::Decode
// 	Decode a MIPS instruction 
//----------------------------------------------------------------------

void
Instruction::Decode()
{
    OpInfo *opPtr;
    
    rs = (value >> 21) & 0x1f;
    rt = (value >> 16) & 0x1f;
    rd = (value >> 11) & 0x1f;
    opPtr = &opTable[(value >> 26) & 0x3f];
    opCode = opPtr->opCode;
    if (opPtr->format == IFMT) {
	extra = value & 0xffff;
	if (extra & 0x8000) {
    	   extra |= 0xffff0000;
	}
    } else if (opPtr->format == RFMT) {
	extra = (value >> 6) & 0x1f;
    } else {
	extra = value & 0x3ffffff;
    }
    if (opCode == SPECIAL) {
	opCode = specialTable[value & 0x3f];
    } else if (opCode == BCOND) {
	int i = value & 0x1f0000;

	if (i == 0) {
    	    opCode = OP_BLTZ;
	} else if (i == 0x10000) {
    	    opCode = OP_BGEZ;
	} else if (i == 0x100000) {
    	    opCode = OP_BLTZAL;
	} else if (i == 0x110000) {
    	    opCode = OP_BGEZAL;
	} else {
    	    opCode = OP_UNIMP;
	}
    }
}

//----------------------------------------------------------------------
// Mult
// 	Simulate R2000 multiplication.
// 	The words at *hiPtr and *loPtr are overwritten with the
// 	double-length result of the multiplication.
//----------------------------------------------------------------------

static void
Mult(int a, int b, bool signedArith, int* hiPtr, int* loPtr)
{
    if ((a == 0) || (b == 0)) {
	*hiPtr = *loPtr = 0;
	return;
    }

    // Compute the sign of the result, then make everything positive
    // so unsigned computation can be done in the main loop.
    bool negative = FALSE;
    if (signedArith) {
	if (a < 0) {
	    negative = !negative;
	    a = -a;
	}
	if (b < 0) {
	    negative = !negative;
	    b = -b;
	}
    }

    // Compute the result in unsigned arithmetic (check a's bits one at
    // a time, and add in a shifted value of b).
    unsigned int bLo = b;
    unsigned int bHi = 0;
    unsigned int lo = 0;
    unsigned int hi = 0;
    for (int i = 0; i < 32; i++) {
	if (a & 1) {
	    lo += bLo;
	    if (lo < bLo)  // Carry out of the low bits?
		hi += 1;
	    hi += bHi;
	    if ((a & 0xfffffffe) == 0)
		break;
	}
	bHi <<= 1;
	if (bLo & 0x80000000)
	    bHi |= 1;
	
	bLo <<= 1;
	a >>= 1;
    }

    // If the result is supposed to be negative, compute the two's
    // complement of the double-word result.
    if (negative) {
	hi = ~hi;
	lo = ~lo;
	lo++;
	if (lo == 0)
	    hi++;
    }
    
    *hiPtr = (int) hi;
    *loPtr = (int) lo;
}
