program p10035;
{
@JUDGE_ID:  20044WC 10035 PASCAL "Kindergarten Maths"
}
var
	n     : longint;
	a,b   : longint;
	c     : longint;
begin
	while true do begin
	n := 0;
	c := 0;
	readln(a,b);
	if (a=0) and (b=0) then exit;
	while (a>0) or (b>0) do begin
		c := ( (a mod 10)  + (b mod 10) + c) div 10;
		a := a div 10;
		b := b div 10;
		if c > 0 then inc(n);
	end;
	if n = 0 then writeln('No carry operation.');
	if n = 1 then writeln(n, ' carry operation.');
	if n > 1 then writeln(n, ' carry operations.');
	end;
end.
