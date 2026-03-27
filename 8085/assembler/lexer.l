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
"XCHG"       return XCHG_TOKEN;
"SPHL"       return SPHL_TOKEN;
"XTHL"       return XTHL_TOKEN;
"PCHL"       return PCHL_TOKEN;
"LDA"       return LDA_TOKEN;
"LDAX"       return LDAX_TOKEN;
"STA"       return STA_TOKEN;
"STAX"       return STAX_TOKEN;
"LHLD"      return LHLD_TOKEN;
"SHLD"      return SHLD_TOKEN;
"INX"       return INX_TOKEN;
"DCX"       return DCX_TOKEN;
"INR"       return INR_TOKEN;
"DCR"       return DCR_TOKEN;
"ADD"       return ADD_TOKEN;
"ADC"       return ADC_TOKEN;
"ADI"       return ADI_TOKEN;
"ACI"       return ACI_TOKEN;
"DAD"       return DAD_TOKEN;
"SUB"       return SUB_TOKEN;
"SBB"       return SBB_TOKEN;
"SUI"       return SUI_TOKEN;
"ANA"       return ANA_TOKEN;
"ANI"       return ANI_TOKEN;
"ORA"       return ORA_TOKEN;
"ORI"       return ORI_TOKEN;
"XRA"       return XRA_TOKEN;
"XRI"       return XRI_TOKEN;
"CMP"       return CMP_TOKEN;
"CPI"       return CPI_TOKEN;
"RST"       return RST_TOKEN;
"MOV"       return MOV_TOKEN;
"MVI"       return MVI_TOKEN;
"LXI"       return LXI_TOKEN;
"JMP"       return JMP_TOKEN;
"JNC"       return JNC_TOKEN;
"JC"       return JC_TOKEN;
"JP"        return JP_TOKEN;
"JM"        return JM_TOKEN;
"JZ"        return JZ_TOKEN;
"JNZ"       return JNZ_TOKEN;
"JPE"       return JPE_TOKEN;
"JPO"       return JPO_TOKEN;
"CALL"      return CALL_TOKEN;
"CC"        return CC_TOKEN;
"CNC"       return CNC_TOKEN;
"CM"        return CM_TOKEN;
"CP"        return CP_TOKEN;
"CZ"        return CZ_TOKEN;
"CNZ"       return CNZ_TOKEN;
"CPE"       return CPE_TOKEN;
"CPO"       return CPO_TOKEN;
"RC"        return RC_TOKEN;
"RNC"       return RNC_TOKEN;
"RP"        return RP_TOKEN;
"RM"        return RM_TOKEN;
"RZ"        return RZ_TOKEN;
"RNZ"       return RNZ_TOKEN;
"RPE"       return RPE_TOKEN;
"RPO"       return RPO_TOKEN;
"RLC"       return RLC_TOKEN;
"RRC"       return RRC_TOKEN;
"RAL"       return RAL_TOKEN;
"RAR"       return RAR_TOKEN;
"RIM"       return RIM_TOKEN;
"SIM"       return SUI_TOKEN;
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
[A-Za-z_][A-Za-z0-9_]*:          return LABEL_NAME;
[A-Za-z_][A-Za-z0-9_]*          return LABEL_VAL;
([1-7]|[567]\.5)        return RSTNUM_VALUE;
[0-9A-Fa-f]{2}[Hh]    return DATA_VALUE;
[0-9A-Fa-f]{4}[Hh]    return DATA16_VALUE;
[ \t\r\n]+            /* ignore */ 
;.*                 /* ignore */;
.                     return yytext[0];

%%
