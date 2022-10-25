global _greet
global _prompt_line
global _shut
global _except
global _disk_buff_ptr

global _cmd_ECHO
global _cmd_COLOR
global _cmd_NONE
global _cmd_CLEAR
global _cmd_SHUTDOWN

_greet:
    times (31) db '-'
	db ' Enter A Command  '
	times (31) db '-'
	db 0

_prompt_line:
    db '>>> ', 0

_shut:
    db 'Shutting Down...', 0
	
_except:
    db 'A CPU Exception Has Occured: ', 0

_disk_buff_ptr:
    dd 0

	
_cmd_ECHO:
	db 'ECHO', 0

_cmd_COLOR:
	db 'COLOR', 0

_cmd_NONE:
    db 'Command Not Found!', 0

_cmd_CLEAR:
    db 'CLEAR', 0

_cmd_SHUTDOWN:
    db 'SHUTDOWN', 0


