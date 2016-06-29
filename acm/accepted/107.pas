program p107;
{
	@JUDGE_ID:  20044WC 107 PASCAL "Logarithmic Mathematics"
}
{
	Algorithm:
	
	The question is basically to solve the equation....

	a = (n+1)^t
	b = n^t

	...

	log(a)/log(b) = log(n+1)/log(n);

	then by bisection, attempt to find n
	t can be found after n is found (trivial)

	Then the rest are simple trivial calculations
}
const
	threshold = 0.00000001;
var
	a,b,e,m,f,i,n,t : longint;
	lazy,stack : longint;			{lazy = non-working cats, stack = summed height }
	r : real;

function pow(a,n:longint) : longint; var i,t : longint;
begin
	t := 1;
	for i := 1 to n do begin
		t := a * t;
	end;
	pow := t;
	exit;
end;

begin
	while not eof do begin
		readln(a,b);
		if (a=0) and (b=0) then break;
		{ handle case a = 1}
		if (a=1) then begin
			writeln('0 1');
			continue;
		end;
		{ handle case t = 1 }
		if (a = b + 1) then begin
			writeln('1 ', a+b);
			continue;
		end;
		
		{ Bi-section implemented by Binary Search!!! - might be flawed!! }
		e := 2;
		f := 65537; { We assume everything's in this range... in fact largest n should be <= 2^16 (if a,b <= 2^32 and t > 2) }
		r := 0;
		while true do begin
			m := (e+f) div 2;
			r := ln(m)/ln(m+1) - ln(b)/ln(a);
			{ an approximation optimization, the value must be close enough before we use sth harder to test }
			if (abs(r) < threshold) then begin
				{ find n, t }
				n:=m;
				t:=round(ln(b)/ln(n));
				{ if found then break }
				if (a = pow(n+1,t)) and (b = pow(n,t)) then break;
			end;
			if e = f then break;
			if r < 0 then e := m+1;
			if r > 0 then f := m;
		end;
		
		{ handle the case where b = 1 }
		{ this is put after bin search because it "works"... although the better
		  practice would be putting it next to case a = 1 }
		if (b=1) then begin
			n := 1;
			t:=round(ln(a)/ln(2));
		end;
		
		{ calculations }
		lazy := 0;
		stack := 0;
		
		for i := 0 to t-1 do begin
			lazy := lazy + pow(n,i);
			stack := stack + (pow(n,t-i) * pow(n+1,i));
		end;
		stack := stack + pow(n+1,t);
		writeln(lazy, ' ', stack);
	end;
end.

