program test;
var
	s,e,x: array[1..100000] of longint;
	m : array[1..100000] of byte;
	i,j,k : longint;
	testcases : longint;
	n : longint;
	c : char;
begin
	readln(testcases);

	for k := 1 to testcases do begin
		readln(n);
		for i := 1 to n do begin
			read(c);
			s[i] := ord(c);
			j := 0;
			while true do begin
				read(c);
				if (c < 'a') or (c > 'z') then break;
				e[i] := ord(c);
			end;
		end;
		for i := 1 to n do begin
			for j := 1 to n do begin
				if e[i] = s[j] then begin
					x[i] := j;
				end;
			end;
		end;
	end;
end.

