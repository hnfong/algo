program greycode;
{
	attempts to solve greycode (HKOI2001J Q1)
	still undone
}
var
	i,j : longint;
{	a : array[0..10,0..1024] of longint;}
	tmp : string;
	t : longint;
	a : string;
begin
	readln(a);
	for j := 1 to 1024 do begin
		tmp := '';
		for i := 1 to 10 do begin
			if ((((j + (1 shl (i-1)))-1) div (1 shl i)) mod 2) = 1 then tmp := tmp + '1';
		end;
		if tmp = a then t := j;
	end;
	writeln(t);
	for j := t to 1024 do begin
		for i := 1 to 10 do begin
			write((((j + (1 shl (i-1)))-1) div (1 shl i)) mod 2);
		end;
		writeln;
	end;
end.

