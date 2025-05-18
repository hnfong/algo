program p10131;
{
	@JUDGE_ID:  20044WC 10131 PASCAL "Grey"
}
var
	i,j,k,n : longint;
	a : array[1..1000] of longint;
	b : array[1..1000] of longint;
	c : array[1..1000] of longint;
	u : array[1..1000] of boolean;
	incr : boolean;
procedure discard(x : longint);
var i,j,k : longint;
begin
	for i := x+1 to n do begin
		a[i-1] := a[i];
		b[i-1] := b[i];
		c[i-1] := c[i];
	end;
	dec(n);
end;
begin
	fillchar(u, sizeof(u), true);
	n := 0;
	while not eof do begin
		inc(n);
		readln(a[n], b[n]);
		c[n] := n;
	end;

	for i := 1 to n do begin
		for j := i downto 2 do begin
			if a[j] < a[j-1] then begin
				k := a[j];
				a[j] := a[j-1];
				a[j-1] := k;

				k := b[j];
				b[j] := b[j-1];
				b[j-1] := k;
				
				k := c[j];
				c[j] := c[j-1];
				c[j-1] := k;
			end;
		end;
	end;
	
	for i := 1 to n do begin
		for j := i downto 2 do begin
			if (a[j] = a[j-1]) and (b[j] < b[j-1]) then begin
				k := a[j];
				a[j] := a[j-1];
				a[j-1] := k;

				k := b[j];
				b[j] := b[j-1];
				b[j-1] := k;
				
				k := c[j];
				c[j] := c[j-1];
				c[j-1] := k;
			end;
		end;
	end;

	i := 2;
	while i <= n do begin
		{for j := 1 to n do begin if j = i then write('!'); writeln(a[j]:6, b[j]:6, c[j]:6); end; writeln;}

		if a[i] = a[i-1] then begin
			j := i;
			if j > 2 then begin
				while (b[j] < b[j-2]) do begin discard(j-1); end;
				discard(i);
			end else begin
				discard(i-1) ;
			end;
			continue;
		end;
		if b[i] > b[i-1] then begin discard(i-1); continue; end;
		if b[i] = b[i-1] then begin discard(i); continue; end;
		inc(i);
	end;

	{writeln('answer'); for i := 1 to n do begin writeln(a[i]:6, b[i]:6, c[i]:6); end;}
	writeln(n);
	for i := 1 to n do writeln(c[i]);
end.
