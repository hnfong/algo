{
PROG: gift1
ID: sydneyf1
}
program gift;
var
	a1 : array[1..10] of integer;
	a2 : array[1..10] of integer;
	a3 : array[1..10] of integer;
	nam : array[1..10] of string[15];
	n : longint;
	i,j,k : longint;
	s : string[15];
	per : longint;
	dist : longint;
begin
	assign(input,'gift1.in');
	assign(output,'gift1.out');
	reset(input);
	rewrite(output);

	fillchar(a1,sizeof(a1),0);
	fillchar(a2,sizeof(a2),0);
	fillchar(a3,sizeof(a3),0);
	readln(n);
	for i := 1 to  n do begin
		readln(nam[i]);
	end;

	for i := 1 to n do begin
		readln(s);
		for j := 1 to n do begin
			if nam[j] = s then begin
				per := j;
				break;
			end;
		end;
		readln(a1[per],dist);
		for k := 1 to dist do begin
			readln(s);
			for j := 1 to n do begin
				if nam[j] = s then begin
					a2[j] := a2[j] + a1[per] div dist;
					break;
				end;
			end;
		end;
		if dist > 0 then a3[per] := a1[per] mod dist else a3[per] := a1[per];
	end;

	for i := 1 to n do begin
		writeln(nam[i],' ', a2[i]+a3[i]-a1[i]);
	end;
	close(input);
	close(output);
end.
