program p10424;
{
@JUDGE_ID: 20044WC 10424 PASCAL
}

var
	i,j,k  : longint;
	s1,s2 : string[255];
	z1,z2  : longint;
	d	: double;
function cval(c:char) : longint;
begin
	cval := 0;
	if (c >= 'A') and (c <= 'Z') then begin
		cval := ord(c)-64;
	end;
end;

function addup(x:longint):longint;
var
	z : longint;
begin
	z := x;
	while z >= 10 do begin
		z := 0;
		while x > 0 do begin
			z := z + x mod 10;
			x := x div 10;
		end;
		x := z;
	end;
	addup := z;
end;

begin
	while not eof do begin
		readln(s1);
		readln(s2);
		s1 := upcase(s1);
		s2 := upcase(s2);
		z1 := 0;
		for i := 1 to length(s1) do begin
			z1 := z1 + cval(s1[i]);
		end;
		z2 := 0;
		for i := 1 to length(s2) do begin
			z2 := z2 + cval(s2[i]);
		end;
		j := addup(z1);
		k := addup(z2);
		if j > k then begin
			writeln( (k / j)*100:0:2 , ' %');
		end else begin
			writeln( (j / k)*100:0:2 , ' %');
		end;
	end;
end.
