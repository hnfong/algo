program p113;
{
@JUDGE_ID: 20044WC 113 PASCAL "Double"
}
var
	i,j,k,n,p : extended;
begin
	while not eof do begin
		readln(n);
		readln(p);
		writeln(round(power( 2.718281828, (ln(p)/n) )));
	end;
end.

