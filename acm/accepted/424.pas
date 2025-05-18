program p424;
{
	@JUDGE_ID:  20044WC 424 PASCAL "HPA"
}
var
	i,j,k   :longint;
	sum : array[1..101] of longint;
	t : array[1..101] of longint;
	c : char;
	carry : longint;
	start : boolean;
begin
	fillchar(sum,sizeof(sum),0);
	while not eof do begin
		fillchar(t,sizeof(t),0);
		k := 0; carry := 0;
		while not eoln do begin
			inc(k);
			read(c);
			t[k] := ord(c) - 48;
		end; readln;
		if (k=1) and (t[k]=0) then break;
		for i := 1 to k do begin
			sum[i] := (sum[i] + t[k+1-i] + carry);
			carry := sum[i] div 10;
			sum[i] := sum[i] mod 10;
		end;
		sum[k+1] := sum[k+1] + carry;
	end;
	start := false;
	for i := 101 downto 1 do begin
		if sum[i] > 0 then start := true;
		if start then write(sum[i], '');
	end;
	writeln;
end.
