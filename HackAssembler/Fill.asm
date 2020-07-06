(LOOP)
	@SCREEN
	D = A
	@i
	M = D
	@KBD
	D = A
	@end
	M = D // as long as i is less than end, continue moving along screen 
(DRAW)
	@i
	D = M
	@end
	D = M - D
	@LOOP
	D;JEQ
	@KBD
	D = M
	@BLACK
	D;JNE
	@WHITE
	D;JEQ
(BLACK)
	@i
	D = M
	A = D
	M = -1
	@NEXT
	0;JMP
(WHITE)
	@i
	D = M
	A = D
	M = 0
	@NEXT
	0;JMP
(NEXT)
	@i
	M = M + 1
	@DRAW
	0;JMP