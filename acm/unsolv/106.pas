program p106;
var
	i,j,k : longint;
	n  : longint;
	x,y,z : longint;
	r1,r2 : int64;
function gcd(a,b:longint) : longint;
begin
	while true do begin
		if a = 0 then begin
			gcd := b;
			exit;
		end;
		if b = 0 then begin
			gcd := a;
			exit;
		end;
		if a > b then begin
			a := a mod b;
		end else begin
			b := b mod a;
		end;
	end;
end;

begin
	readln(n);
	for x := 1 to n do begin
		for y := x+1 to n do begin
			r1 := x*x+y*y;
			if abs(sqrt(r1) - round(sqrt(r1))) < 0.00001 then begin
				z := round(sqrt(r1));
				r2 := z*z;
				if r1 <> r2 then continue;
				if (gcd(x,y) = 1) and (gcd(y,z)=1) and (gcd(x,z)=1) then
				writeln(x,'^2 + ',y,'^2 = ',z,'^2');
				{break;}
			end;
		end;
	end;
end.
