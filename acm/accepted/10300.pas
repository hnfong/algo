program p10300;
{
	@JUDGE_ID:  20044WC 10300 PASCAL "Stupid"
}

var
	n,i,j,k,t,a,b,c : longint;
begin
	readln(n);
	for i := 1 to n do begin
		readln(k);
		t := 0;
		for j := 1 to k do begin
			readln(a,b,c);
			t := t + a*c;
		end;
		writeln(t);
	end;
end.
