program p1020;
var
	i,j,k,t,nx,ny,z,e : longint;
	w : array[0..50000] of longint;
	m : array[0..50000] of longint;
	c : array[0..50000] of longint;
begin
	z:=0;
	fillchar(c,sizeof(c),0);
	fillchar(w,sizeof(w),0);
	fillchar(m,sizeof(m),0);
	readln(nx,ny);
	for i := 1 to nx do readln(j, w[i]);
	k := nx;
	while k > 0 do begin
		k := k div 3+1;
		for i := 1 to nx do begin
			t := w[i];
			j := i;
			while (j>k) and (t<w[j-k]) do begin
				dec(j,k);
				w[j+k] := w[j];
			end;
			w[j] := t;
		end;
		if k = 1 then break;
	end;

	for i := nx+1 to nx+ny do readln(j, w[i]);
	k := ny;
	while k > 0 do begin
		k := k div 3+1;
		for i := nx+1 to nx+ny do begin
			t := w[i];
			j := i;
			while (j>k+nx) and (t<w[j-k]) do begin
				dec(j,k);
				w[j+k] := w[j];
			end;
			w[j] := t;
		end;
		if k = 1 then break;
	end;
	i := 1; j := nx+1;
	while (i<=nx) and (j<=nx+ny) do begin
		if w[i]=w[j] then begin
			k := j;
			while w[i] = w[k] do begin
				inc(k);
				inc(z);
			end;
			inc(i);
		end;
		if w[i]<w[j] then begin inc(i); continue; end;
		if w[i]>w[j] then begin inc(j); continue; end;
	end;
	writeln(z);
end.

