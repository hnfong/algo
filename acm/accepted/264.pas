program p264;
{
	@JUDGE_ID: 20044WC 264 PASCAL "Maths"
}
var
	i,j,k : longint;
	c : int64;
	n : longint;
	nc2  : int64;
	a,b : int64;
begin
	while not eof do begin
		readln(n);
		b := 0;
		c := trunc((-1 + sqrt(1+8*n)) / 2 + 0.99999999 )+1;
		{ adds up to c }
		nc2 := ((c-1)*(c-2)div 2);
		a := n-nc2;
		b := c - a;
		if c mod 2 = 1 then begin
			writeln('TERM ', n, ' IS ',a, '/', b);
		end else begin
			writeln('TERM ', n, ' IS ',b, '/', a);
		end;
	end;
end.
