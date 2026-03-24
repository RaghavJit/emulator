%{
#include "parser.tab.h"
#include <ctype.h>
#include <string.h>
%}
%option noyywrap

%%
"PUSH"      return PUSH_TOKEN;
"POP"       return POP_TOKEN;
"IN"        return IN_TOKEN;
"OUT"       return OUT_TOKEN;
"DAA"       return DAA_TOKEN;
"CMA"       return CMA_TOKEN;
"CMC"       return CMC_TOKEN;
"STC"       return STC_TOKEN;
"RET"       return RET_TOKEN;
"EI"        return EI_TOKEN;
"DI"        return DI_TOKEN;
"HLT"       return HLT_TOKEN;
"NOP"       return NOP_TOKEN;
"LDA"       return LDA_TOKEN;
"STA"       return STA_TOKEN;
"LHLD"      return LHLD_TOKEN;
"SHLD"      return SHLD_TOKEN;
"INX"       return INX_TOKEN;
"DCX"       return DCX_TOKEN;
"INR"       return INR_TOKEN;
"DCR"       return DCR_TOKEN;
"ADD"       return ADD_TOKEN;
"SUB"       return SUB_TOKEN;
"ANA"       return ANA_TOKEN;
"ORA"       return ORA_TOKEN;
"XRA"       return XRA_TOKEN;
"CMP"       return CMP_TOKEN;
"RST"       return RST_TOKEN;
"MOV"       return MOV_TOKEN;
"MVI"       return MVI_TOKEN;
"LXI"       return LXI_TOKEN;
"A"         return A_REG;
"B"         return B_REG;
"C"         return C_REG;
"D"         return D_REG;
"E"         return E_REG;
"H"         return H_REG;
"L"         return L_REG;
"BC"        return BC_REG;
"DE"        return DE_REG;
"HL"        return HL_REG;
"SP"        return SP_REG;
","         return COMMA_VAL;
";"         return SEMCOL_VAL;
([1-7]|[567]\.5)        return RSTNUM_VALUE;
[0-9A-Fa-f]{2}[Hh]    return DATA_VALUE;
[0-9A-Fa-f]{4}[Hh]    return DATA16_VALUE;
[ \t\r\n]+            /* ignore */ 
;.*                 /* ignore */;
.                     return yytext[0];

%%
