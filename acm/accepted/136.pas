program p136;
{
	@JUDGE_ID:  20044WC 136 PASCAL "Siliconism"
}
const
	nump = 3;
	hc : array[1..nump] of integer = (2,3,5);
var
	a : array[0..1500] of longint;
	p : array[1..nump] of longint;
	i,n : longint;
	min,t : longint;
begin
	{ we consider 1 as an ugly number, i.e. the sequence is 1,2,3,4,5,6,8... etc }

	n := 1;
	a[1] := 1;
	for i := 1 to nump do p[i] := 1;
	
	while n < 1500 do begin
		inc(n);
		min := 2147483647;
		for i := 1 to nump do begin
			t := a[p[i]] * hc[i];
			if (t < min) then begin
				min := t;
			end;
		end;
		for i := 1 to nump do begin
			if (a[p[i]] * hc[i]) = min then inc(p[i]);
		end;
		a[n] := min;
	end;
	writeln('The 1500''th ugly number is ', a[1500]:0,'.');
end.
{ The following is the HARDCODED version }
{
program p136;
begin
	writeln('The 1500''th ugly number is 859963392.');
end.
}
