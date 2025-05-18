program p1031;
var
	i,j,k : longint;
	n : longint;
	w : array[1..26] of char;
	nump : longint;
	l : longint;
	o : array[1..26] of char;
	u2 : array[1..26] of boolean;
	c : char;
	u  :array['A'..'Z'] of longint;

procedure permutate(x : longint);
var
	i,j : longint;
	u  :array['A'..'Z'] of longint;
begin
	fillchar(u,sizeof(u),0);
	{writeln(o, ' ', x);
	for i := 1 to n do write(u2[i], ' '); writeln;}
	if nump >= k then exit;
	u2[x] := true;
	inc(l);
	o[l] := w[x];
	if l = n then begin
		writeln(o);
		inc(nump);
	end else
		for i := 1 to n do begin
			if (u[w[i]] = 0) and (not u2[i]) then begin
				inc(u[w[i]]);
				permutate(i);
			end;
		end;
	o[l] := ' ';
	dec(l);
	u2[x] := false;
end;

begin
	fillchar(w,sizeof(w),0);
	fillchar(u2,sizeof(u2),0);
	l := 0;
	readln(n,k);
	readln(w);
	for i := 1 to n do begin
		for j := n downto 2 do begin
			if w[j] < w[j-1] then begin
				c := w[j];
				w[j] := w[j-1];
				w[j-1]:=c;
			end;
		end;
	end;
	nump := 0;
	for i := 1 to n do begin
		if (u[w[i]] = 0) and (not u2[i]) then begin
			inc(u[w[i]]);
			permutate(i);
		end;
	end;
end.

