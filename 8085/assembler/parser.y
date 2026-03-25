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
%token STA_TOKEN
%token LHLD_TOKEN
%token SHLD_TOKEN
%token INX_TOKEN
%token DCX_TOKEN
%token INR_TOKEN 
%token DCR_TOKEN
%token ADD_TOKEN
%token SUB_TOKEN
%token ANA_TOKEN
%token ORA_TOKEN
%token XRA_TOKEN
%token CMP_TOKEN
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
%token ADDRESS
%token COMMA_VAL
%token SEMCOL_VAL
%token COLON_VAL 
%token LABEL_NAME

%%
S: 
     S LBL X0 SEMCOL
    | S LBL X1 SEMCOL
    | S LBL X2 SEMCOL
    | 
    ;

LBL:
     
    | LABEL_NAME COLON
    ;

X0:
     POP_TOKEN
    | IN_TOKEN
    | OUT_TOKEN
    | DAA_TOKEN
    | CMA_TOKEN
    | CMC_TOKEN
    | STC_TOKEN
    | RET_TOKEN
    | EI_TOKEN
    | DI_TOKEN
    | HLT_TOKEN
    | NOP_TOKEN
    ;

X1:
     PUSH_TOKEN DATA
    | LDA_TOKEN ADDR            
    | STA_TOKEN ADDR            
    | LHLD_TOKEN ADDR           
    | SHLD_TOKEN ADDR           
    | INX_TOKEN REGPAIR         
    | DCX_TOKEN REGPAIR         
    | INR_TOKEN REG             
    | DCR_TOKEN REG             
    | ADD_TOKEN REG             
    | SUB_TOKEN REG             
    | ANA_TOKEN REG
    | ORA_TOKEN REG
    | XRA_TOKEN REG
    | CMP_TOKEN REG
    | RST_TOKEN RSTNUM
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
    ;

COMMA: 
      
      | COMMA_VAL
      ;

SEMCOL: 
      
      | SEMCOL_VAL
      ;

COLON: 
     COLON_VAL
     ;
%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}
