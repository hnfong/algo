program p1021;
type	rec = record
	x,b : longint
	end;
var
	i,j,k,nx,ny,z,e : longint;
	w : array[0..50000] of rec;
	t : rec;
begin
	z:=0;
	fillchar(w,sizeof(w),0);
	readln(nx,ny);
	for i := 1 to nx do readln(w[i].x, w[i].b);
	k := nx;
	while k > 0 do begin
		k := k div 3+1;
		for i := 1 to nx do begin
			t := w[i];
			j := i;
			while (j>k) and (t.b<w[j-k].b) do begin
				dec(j,k);
				w[j+k] := w[j];
			end;
			w[j] := t;
		end;
		if k = 1 then break;
	end;
	for i := nx+1 to nx+ny do readln(w[i].x, w[i].b);
	k := ny;
	while k > 0 do begin
		k := k div 3+1;
		for i := nx+1 to nx+ny do begin
			t := w[i];
			j := i;
			while (j>k+nx) and (t.b<w[j-k].b) do begin
				dec(j,k);
				w[j+k] := w[j];
			end;
			w[j] := t;
		end;
		if k = 1 then break;
	end;
	i := 1; j := nx+1;
	while (i<=nx) and (j<=nx+ny) do begin
		if w[i].b=w[j].b then begin
			k := j;
			while (k<=nx+ny) and (w[i].b = w[k].b) do begin
				writeln(w[i].x,' ',w[i].b, ' ', w[k].x);
				inc(k);
				inc(z);
			end;
			inc(i);
			continue;
		end;
		if w[i].b<w[j].b then begin
			writeln(w[i].x,' ', w[i].b,' null');
			inc(i); continue;
		end;
		if w[i].b>w[j].b then begin
			inc(j); continue;
		end;
	end;
	
	while (i <= nx) do begin
		writeln(w[i].x,' ', w[i].b,' null');
		inc(i);
	end;
end.

