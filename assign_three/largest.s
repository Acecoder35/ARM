    AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
    MOV R1, #0x20000000 

   	MOV R5,#0X2
	MOV R6,#0XB
	MOV R7,#0X8
	
	CMP R5,R6	
	BGT IFTRUE 	;if
	B ELSE		;else
	
IFTRUE	CMP R5,R7
	BLE OVER
	MOV R0, R5
	BL printMsg
	B STOP
		
ELSE CMP R6,R7
	BLE OVER
	MOV R0,R6
	BL printMsg
	B STOP
	
OVER 	MOV R0,R7
	BL printMsg

STOP B STOP
    ENDFUNC
    END