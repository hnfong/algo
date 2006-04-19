program p10324;
{
	@JUDGE_ID:  20044WC 10324 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	n : longint;
	c,l : char;
	dp : array[1..1000000] of longint;
	a,b : longint;
	caseno: longint;
begin
	caseno := 0;
	while not eof do begin
		if eoln then break;
		inc (caseno);
		n := 1;
		read(l);
		dp[n] := 1;
		while not eoln do begin
			inc (n);
			read(c);
			if c = l then begin
				dp[n] := dp[n-1] + 1;
			end else begin
				l := c;
				dp[n] := 1;
			end;
		end;
		readln;
		writeln('Case ', caseno,':');
		{for i := 1 to n do begin
			write(dp[i]:4);
		end;writeln;}
		readln(k);
		for i := 1 to k do begin
			readln(a,b);
			if a > b then begin
				j := a;
				a := b;
				b := j;
			end;
			inc(a);
			inc(b);
			if (dp[b]-(b-a+1) ) >= 0 then writeln('Yes') else writeln('No');
		end;
	end;
end.
