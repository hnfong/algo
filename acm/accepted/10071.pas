program p10071;
{
	@JUDGE_ID:  20044WC 10071 PASCAL "DaP/DyP"
}
var
	a,b : integer;
begin
	while not eof do begin
		readln(a,b);
		writeln(2*a*b);
	end;
end.
