program christmas;
var
	i,j,k : longint;
	n : longint;
begin
	readln(n);
	for j := 1 to n do begin
		for i := 1 to n-j do begin write(' '); end;
		for i := 1 to j*2-1 do begin write('*'); end;
		for i := 1 to n-j do begin write(' '); end;
		writeln;
	end;
	for i := 1 to n-1 do begin write(' '); end; write('*'); writeln;
	for i := 1 to n-1 do begin write(' '); end; write('*'); writeln;
end.
