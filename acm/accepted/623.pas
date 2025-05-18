program x623;
{
	@JUDGE_ID:  20044WC 623 PASCAL "Siliconism"
}
const
	base = 10;
var
	a : array[0..500,1..1200] of longint;
	i,j,k : longint;
	n : longint;
	s : string;
procedure dump(x : longint);
var 	i : longint; t : boolean; j : longint;
begin
	t := false;
	j := 0;
	for i := 1136 downto 1 do begin
		if (a[x,i] > 0) then t := true;
		if t = false then continue;
		inc(j);
		if (j > 80) then begin
{			writeln;}
			j := j - 80;
		end;
		write(a[x,i]:1);
	end;
	writeln;
end;

begin
	fillchar(a, 501*1200*4 , 0);
	a[0,1] := 1;
	a[1,1] := 1;
	for i := 1 to 500 do begin
		for j := 1 to 1200 do begin
			a[i,j] := a[i-1,j] * i;
		end;
		for j := 1 to (1200-1) do begin
			a[i,j+1] := a[i,j+1] + a[i,j] div base;
			a[i,j] := a[i,j] mod base;
		end;
	end;
	while (not eof(input)) do begin
		readln(s);
		val(s, n, i);
		if (n <= 0) then continue;
		writeln(n:1, '!');
		dump(n);
	end;
end.

