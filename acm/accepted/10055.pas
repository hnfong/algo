program test;

{
	JUDGE_ID: 20044WC PASCAL 10055
}
var
	a,b : int64;
begin
	while not eof do begin
		readln(a,b);
		writeln(abs(a-b));
	end;
end.
