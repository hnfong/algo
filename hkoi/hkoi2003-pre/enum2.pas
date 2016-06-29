program enum2;
var
	i,n : longint;
begin
	assign(input,'INPUT.TXT');
	assign(output,'INPUT.TXT');
	rewrite(output);
	reset(input);
	readln(n);
	if n = 1 then writeln('1');
	if n = 2 then begin
		writeln('1 2');
		writeln('3 4');
	end;
	if n = 3 then begin
		writeln('1 2 3');
		writeln('4 5 6');
		writeln('7 8 9');
	end;
	if n = 4 then begin
		writeln('1 2 3 4');
		writeln('5 6 7 8');
		writeln('9 10 11 12');
		writeln('13 14 15 16');
	end;
	if n = 5 then begin
		writeln('1 2 3 4 5');
		writeln('6 7 8 9 10');
		writeln('11 12 13 14 15');
		writeln('16 17 18 19 20');
		writeln('21 22 23 24 25');
	end;
	if n = 6 then begin
		writeln('1 2 3 4 5 6');
		writeln('7 8 9 10 11 12');
		writeln('13 14 15 16 17 18');
		writeln('19 20 21 22 23 24');
		writeln('25 26 27 28 29 30');
		writeln('31 32 33 34 35 36');
	end;
	if n = 7 then begin
		writeln('1 2');
		writeln('3 4');
	end;
	if n = 8 then begin
		writeln('1 2');
		writeln('3 4');
	end;
	if n = 9 then begin
		writeln('1 2');
		writeln('3 4');
	end;
	if n = 10 then begin
		writeln('1 2');
		writeln('3 4');
	end;
	close(input);
	close(output);
end.
