program x136;
{
	This is one of the slowest and most naive methods to solve the problem. (1500th Ugly number)
	Btw, it requires ~ 120MB memory to run. Good luck on that!
}
const	
	size = 120000000;
var
	b : boolean;
	a : array[0..size] of byte;
	i,j : longword;
	c : array[1..1600] of longword;

function bget (x : longword) : boolean;
begin
	if (((a[x div 8]) shr (x mod 8)) and 1) = 1 then bget := true else bget := false;
end;

procedure bset (x:longword;y:boolean);
var
	t : byte;
begin
	if y then t := 1 else t := 0;
	t := (t shl (x mod 8)) or a[x div 8];
	a[x div 8] := t;
end;

begin
	fillchar(a, sizeof(a), 0);
	bset(2, true);
	bset(3, true);
	bset(4, true);
	bset(5, true);
	writeln(size * 7);
	j := 0;
	for i := 6 to size * 8 - 10000 do begin
		b := false;
		if ((i mod 2) = 0) and ((((a[(i div 2) div 8]) shr ( (i div 2) mod 8)) and 1) = 1) then b := true;
		if ((i mod 3) = 0) and ((((a[(i div 3) div 8]) shr ( (i div 3) mod 8)) and 1) = 1) then b := true;
		if ((i mod 5) = 0) and ((((a[(i div 5) div 8]) shr ( (i div 5) mod 8)) and 1) = 1) then b := true;
		bset(i, b);
		if b then  begin
			inc (j);
			if (j mod 100 = 0) then writeln(j, ' ', i);
			c[j] := i;
		end;
		if j > 1506 then break;
	end;
	for i := 1 to j do writeln(c[i], ' ');
end.

