program p10110;
{
@JUDGE_ID:  20044WC 10110 PASCAL "All Right......"
}
var
	n : longword;
	f : longint;
begin
	while true do begin
		read(n);
		if n = 0 then break;
		f := round(sqrt(n));
		if f*f=n then writeln('yes') else writeln('no');
	end;
end.
