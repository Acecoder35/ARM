    AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
    MOV R1, #0x20000000 ;base address
	
    MOV R2, #0X2	;values
	MOV R3, #0X7
	MOV R4, #0X9
	MOV R5, #0XB
	MOV R6, #0X1
	
	STR R2,	[R1] 
   	STR R3, [R1, #4]
   	STR R4, [R1, #8]
    STR R5, [R1, #12]
    STR R6, [R1, #16]
	
	MOV R7, #0
	MOV R2, #0
	
FORLOOP	LDR R8,[R1]
	CMP R7 ,R8    
    MOVLT R7, R8
	ADD R2,#01
	CMP R2,#05
	BEQ PRINTING
	ADD R1,#04
	B FORLOOP

PRINTING 	MOV R0,R7
	BL printMsg

STOP B STOP
    ENDFUNC
    END