program p1024;
var	
	i,j,k,n : longint;
	s : ansistring;
	a : array[0..11000] of longint;
	b : array[0..11000] of longint;
	d : array[0..11000] of longint;
	c  : char;
begin
	n := 10900;
	fillchar(a,sizeof(a),0);
	fillchar(a,sizeof(b),0);
	fillchar(a,sizeof(d),0);

	readln(s); j := length(s);
	for i := 1 to j do begin
		a[j-i] := ord(s[i]) - 48;
	end;
	readln(s); j := length(s);
	for i := 1 to j do begin
		b[j-i] := ord(s[i]) - 48;
	end;

	for i := 0 to n do begin
		d[i] := a[i] + b[i];
	end;
	
	for i := 0 to n do begin
		d[i+1] := d[i+1] + (d[i] div 10);
		d[i] := d[i] mod 10;
	end;
	
	j := 0;
	for i := n+1 downto 0 do begin
		if d[i] > 0 then j := 1;
		if j = 1 then write(d[i]);
	end;
end.

