program p10323;
{
	@JUDGE_ID:  20044WC 10323 PASCAL "DaP/DyP"
}
var
	n : longint;
begin
	while not eof do begin
		readln(n);
		if (n < 0) and ((n mod 2) = 0) then writeln('Underflow!');
		if (n < 0) and ((n mod 2) <> 0) then writeln('Overflow!');
		if (n >= 0) and (n <= 7) then writeln('Underflow!');
		if n = 8 then writeln('40320');
		if n = 9 then writeln('362880');
		if n = 10 then writeln('3628800');
		if n = 11 then writeln('39916800');
		if n = 12 then writeln('479001600');
		if n = 13 then writeln('6227020800');
		if (n > 0) and (n > 13) then writeln('Overflow!');
	end;
end.
