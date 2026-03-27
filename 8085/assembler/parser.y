%{
#include <cstdio>
#include <cstdlib>

void yyerror(const char* s);
int yylex();
%}

%token PUSH_TOKEN
%token POP_TOKEN
%token IN_TOKEN
%token OUT_TOKEN
%token DAA_TOKEN
%token CMA_TOKEN
%token CMC_TOKEN
%token STC_TOKEN
%token RET_TOKEN
%token EI_TOKEN
%token DI_TOKEN
%token HLT_TOKEN
%token NOP_TOKEN
%token LDA_TOKEN
%token LDAX_TOKEN
%token STA_TOKEN
%token STAX_TOKEN
%token LHLD_TOKEN
%token SHLD_TOKEN
%token DCX_TOKEN
%token INR_TOKEN 
%token INX_TOKEN 
%token DCR_TOKEN
%token ADD_TOKEN
%token ADC_TOKEN
%token ADI_TOKEN
%token ACI_TOKEN
%token DAD_TOKEN
%token SUB_TOKEN
%token SBB_TOKEN
%token SUI_TOKEN
%token ANA_TOKEN
%token ANI_TOKEN
%token ORA_TOKEN
%token ORI_TOKEN
%token XRA_TOKEN
%token XRI_TOKEN
%token CMP_TOKEN
%token CPI_TOKEN
%token RST_TOKEN
%token MOV_TOKEN
%token MVI_TOKEN
%token LXI_TOKEN
%token A_REG
%token B_REG
%token C_REG 
%token D_REG
%token E_REG
%token H_REG
%token L_REG 
%token BC_REG
%token DE_REG
%token HL_REG 
%token SP_REG
%token RSTNUM_VALUE
%token DATA_VALUE
%token DATA16_VALUE
%token COMMA_VAL
%token LABEL_NAME
%token LABEL_VAL
%token XCHG_TOKEN
%token SPHL_TOKEN
%token XTHL_TOKEN
%token JMP_TOKEN
%token JC_TOKEN
%token JNC_TOKEN
%token JP_TOKEN
%token JM_TOKEN
%token JZ_TOKEN
%token JNZ_TOKEN
%token JPE_TOKEN
%token JPO_TOKEN
%token CALL_TOKEN
%token CC_TOKEN
%token CNC_TOKEN
%token CM_TOKEN
%token CP_TOKEN
%token CZ_TOKEN
%token CNZ_TOKEN
%token CPE_TOKEN
%token CPO_TOKEN
%token RC_TOKEN
%token RNC_TOKEN
%token RP_TOKEN
%token RM_TOKEN
%token RZ_TOKEN
%token RNZ_TOKEN
%token RPE_TOKEN
%token RPO_TOKEN
%token PCHL_TOKEN
%token RLC_TOKEN
%token RRC_TOKEN
%token RAL_TOKEN
%token RAR_TOKEN
%token RIM_TOKEN
%token SIM_TOKEN

%%
S: 
     S LBL X0
    | S LBL X1
    | S LBL X2
    | 
    ;

LBL:
     
    | LABEL_NAME
    ;

X0:
     DAA_TOKEN
    | CMA_TOKEN
    | CMC_TOKEN
    | STC_TOKEN
    | RET_TOKEN
    | EI_TOKEN
    | DI_TOKEN
    | HLT_TOKEN
    | NOP_TOKEN
    | XCHG_TOKEN 
    | SPHL_TOKEN 
    | XTHL_TOKEN 
    | RC_TOKEN
    | RNC_TOKEN
    | RP_TOKEN
    | RM_TOKEN
    | RZ_TOKEN
    | RNZ_TOKEN
    | RPE_TOKEN
    | RPO_TOKEN
    | PCHL_TOKEN
    | RLC_TOKEN
    | RRC_TOKEN
    | RAL_TOKEN
    | RAR_TOKEN
    | RIM_TOKEN
    | SIM_TOKEN
    ;

X1:
     PUSH_TOKEN REGPAIR 
    | POP_TOKEN REGPAIR 
    | IN_TOKEN DATA
    | OUT_TOKEN DATA
    | LDA_TOKEN DATA16 
    | LDAX_TOKEN REGPAIR 
    | STA_TOKEN ADDR            
    | STAX_TOKEN REGPAIR 
    | LHLD_TOKEN DATA16 
    | SHLD_TOKEN ADDR           
    | INX_TOKEN REGPAIR         
    | DCX_TOKEN REGPAIR         
    | DCR_TOKEN REG             
    | ADD_TOKEN REG             
    | ADC_TOKEN REG             
    | ADI_TOKEN DATA 
    | ACI_TOKEN DATA 
    | DAD_TOKEN DATA 
    | SUB_TOKEN REG             
    | SBB_TOKEN REG             
    | SUI_TOKEN DATA 
    | ANA_TOKEN REG
    | ANI_TOKEN DATA
    | ORA_TOKEN REG
    | ORI_TOKEN REG
    | XRA_TOKEN REG
    | XRI_TOKEN REG
    | CMP_TOKEN REG
    | CPI_TOKEN DATA 
    | RST_TOKEN RSTNUM
    | JMP_TOKEN ADDR
    | JC_TOKEN ADDR
    | JNC_TOKEN ADDR
    | JP_TOKEN ADDR
    | JM_TOKEN ADDR
    | JZ_TOKEN ADDR
    | JNZ_TOKEN ADDR
    | JPE_TOKEN ADDR
    | JPO_TOKEN ADDR
    | CALL_TOKEN ADDR
    | CC_TOKEN ADDR
    | CNC_TOKEN ADDR
    | CM_TOKEN ADDR
    | CP_TOKEN ADDR
    | CZ_TOKEN ADDR
    | CNZ_TOKEN ADDR
    | CPE_TOKEN ADDR
    | CPO_TOKEN ADDR
    ;

X2:
     MOV_TOKEN REG COMMA REG         
    | MVI_TOKEN REG COMMA DATA        
    | LXI_TOKEN REGPAIR COMMA DATA16  
    ;
    

REG:
     A_REG
    | B_REG
    | C_REG
    | D_REG
    | E_REG
    | H_REG
    | L_REG
    ;

REGPAIR:
     BC_REG
    | DE_REG
    | HL_REG
    | SP_REG
    ;

RSTNUM:
      RSTNUM_VALUE
    ;

DATA:
      DATA_VALUE
    ;

DATA16:
      DATA16_VALUE
    ;

ADDR:
      DATA16_VALUE 
      | LABEL_VAL
    ;

COMMA: 
      
      | COMMA_VAL
      ;
%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}
