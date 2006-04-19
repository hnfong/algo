program p5103;
var
	i,j,k,n : longint;
	dp : array [1..52] of longint;
	total : longint;
	o : array['A'..'z'] of longint;
	a : array[1..52] of char;
	c : char;
	z,p : longint;
	inp : array[1..52] of char;
begin
	{ init }
	fillchar(dp,sizeof(dp),0);
	
	{ conversion tables }
	for c := 'A' to 'Z' do o[c]:=(ord(c)-64);
	for c := 'a' to 'z' do o[c]:=(ord(c)-96+26);
	for i := 1 to 26 do a[i]:=chr(i+64);
	for i := 27 to 52 do a[i]:=chr(i+96-26);

	{ dp }
	for i := 52 downto 1 do begin
		dp[i] := 1;
		for j := i+1 to 52 do begin
			if i*9 <= j*8 then begin
				dp[i]:=dp[i]+dp[j];
			end;
		end;
	end;
	total := 0;
	for i := 1 to 52 do inc(total, dp[i]);

	{ input }
	n := 0;
	while not eoln do begin
		inc(n);
		read(c);
		inp[n] := c;
	end;
	
	z := 0; p := 0;
	for i := 1 to n do begin
		inc(z);
		for j := 1 to 52 do begin
			if (o[inp[i]]=j) then break;
			if (p*9 <= j*8) then begin
				z := z + dp[j];
			end;
		end;
		p := o[inp[i]];
	end;
	writeln(z);
end.
