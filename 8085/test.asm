LDA 8000H      ; Load first number into A
MOV B, A       ; Copy it to register B

LDA 8001H      ; Load second number into A
ADD B          ; A = A + B

STA 8002H      ; Store result back to memory

HLT            ; Stop
