program p1012;
var
	i,j,k,n,s : longint;
	w : array[0..1000,0..10] of longint;
	r : array[0..1000] of real;
	u : array[1..1000] of boolean;
	v : array[0..10] of record i,m,n : longint; t : real; end;
	map : array[0..99] of longint;
begin
	readln(n);
	fillchar(v,sizeof(v),0);
	fillchar(w,sizeof(w),0);
	for i := 1 to n do begin
		readln(v[i].i, v[i].m);
		map[v[i].i] := i;
	end;
	readln(s);
	for i := 1 to s do begin
		for j := 0 to n do begin
			read(w[i,j]);
		end;
		readln(r[i]);
	end;
	for i := 1 to s do begin
		for j := s downto 2 do begin
			if r[j] > r[j-1] then begin
				r[0] := r[j];
				r[j] := r[j-1];
				r[j-1] := r[0];
				w[0] := w[j];
				w[j] := w[j-1];
				w[j-1] := w[0];
			end;
		end;
	end;
	fillchar(u,sizeof(u),false);
	for i := 1 to n do begin { ith choice }
		for j := 1 to s do begin { student }
			k := map[w[j,i]];
			if (v[k].n < v[k].m) and (not u[j]) then begin
				inc(v[k].n);
				v[k].t := v[k].t + r[j];
				u[j] := true;
			end;
		end;
	end;
	writeln('School    No. of students    Average score');
	writeln('******************************************');
	for i := 1 to n do begin
		for j := n downto 2 do begin
			if v[j].i < v[j-1].i then begin
				v[0] := v[j];
				v[j] := v[j-1];
				v[j-1] := v[0];
			end;
		end;
	end;
	for i := 1 to n do begin
		{ ZERO }
		if v[i].n > 0 then
		if v[i].i < 10 then
		writeln('  0',v[i].i,v[i].n:14 , v[i].t / v[i].n:20:2,'    ') else
		writeln(v[i].i:4,v[i].n:14 , v[i].t / v[i].n:20:2,'    ');
	end;
end.
