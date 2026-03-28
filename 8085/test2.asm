 LXI H, 2501H    
                 MOV B, M       
                 MVI A, 00H     
                 MOV D, B       
                 DCR B         
          START: JZ  CNT       
                 MOV E, B       
            MUL: ADD D         
                 DCR E         
                 JNZ MUL       
                 MOV D, A       
                 MVI A, 00H     
                 DCR B         
                 JMP START     
            CNT: MOV A, D       
                 HLT         
