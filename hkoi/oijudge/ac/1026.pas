program p1026;
var
	i,j,k,na,nb : longint;
	a,b,w : array[0..10000] of longint;
	t : array[0..10000] of longint;
	sign : longint;
	c : char;
procedure swrite(x:longint);
begin
	if x < 10 then write(0);
	write(x);
end;

begin
	sign := 1;
	fillchar(a,sizeof(a),0);
	fillchar(b,sizeof(b),0);
	fillchar(w,sizeof(w),0);
	na := 0;
	while not eoln do begin
		read(c);
		if c = '-' then begin sign := -1 * sign; continue; end;
		inc(na);
		a[na] := ord(c)-48;
	end;readln;
	nb := 0;
	while not eoln do begin
		read(c);
		if c = '-' then begin sign := -1 * sign; continue; end;
		inc(nb);
		b[nb] := ord(c)-48;
	end;readln;
	
	for i := 1 to na div 2 do begin
		k := a[i];
		a[i] := a[na-i+1];
		a[na-i+1] := k;
	end;
	for i := 1 to nb div 2 do begin
		k := b[i];
		b[i] := b[nb-i+1];
		b[nb-i+1] := k;
	end;
	for i := 1 to 10000 do t[i] := a[i];
	fillchar(a,sizeof(a),0);
	for i := 1 to na do begin
		inc(a[(i+1) div 2], t[i] * power(10, (i+1) mod 2));
	end;
	na := (na+1) div 2;
	for i := 1 to 10000 do t[i] := b[i];
	fillchar(b,sizeof(b),0);
	for i := 1 to nb do begin
		inc(b[(i+1) div 2], t[i] * power(10, (i+1) mod 2));
	end;
	nb := (nb+1) div 2;
	
	{for i := 1 to na do write(a[i],' ');writeln;
	for i := 1 to nb do write(b[i],' ');writeln;}

	for i := 1 to na do begin
		for j := 1 to nb do begin
			w[i+j-1]:=w[i+j-1]+a[i]*b[j];
		end;
	end;
	for i := 2 to 10000 do begin
		w[i] := w[i] + w[i-1] div 100;
		w[i-1] := w[i-1] mod 100;
	end;
	k := 0;
	for i := 10000 downto 1 do begin
		if w[i]>0 then begin k := i; break; end;
	end;
	if (sign = -1) and (k>0) then write('-',w[k]) else write(w[k]);
	for i := k-1 downto 1 do begin
		swrite(w[i]);
	end;
	writeln;
end.

