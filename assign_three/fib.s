    AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
	MOV R0,#0
	BL printMsg	

	MOV R0,#1
	BL printMsg
	
	MOV R7,#10
	
	MOV R5,#0
	MOV R6,#1
	
LOOP	CMP R7,#00
	BEQ STOP
	ADD R4,R5,R6
	MOV R0,R4	
	BL printMsg
	MOV R5,R6
	MOV R6,R4
	SUB R7,#01	
	B LOOP
	
STOP B STOP
    ENDFUNC
    END