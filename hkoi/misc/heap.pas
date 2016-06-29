procedure heapadd(x:longint;v:double);
var
	t : qtype;
	i : longint;
begin
	if u[x] then exit;
	writeln('heapadd (', x, ' ', v:0:3, ')');
	inc(addcount);
	inc(hs);
	i := hs;
	q[i].x := x;
	q[i].v := v;
	while (i > 1) and (q[i div 2].v > q[i].v) do begin
		t := q[i div 2];
		q[i div 2] := q[i];
		q[i] := t;

		i := i div 2;
	end;
end;

function heappop : qtype;
var
	t : qtype;
	r : qtype;
	i, s : longint;
begin
	r := q[1];
	q[1] := q[hs];
	dec(hs);
	i := 1;
	while true do begin
		if (i * 2) > hs then break; { if no child exists }
		if (q[i].v < q[i * 2].v) and (q[i].v < q[i * 2 + 1].v) then break; { if this is the place }
		{ if only left child exists }
		if (i * 2 + 1) > hs then begin
			s := i * 2;
		end else begin
			if q[i*2].v < q[i*2+1].v then s := i * 2 else s := i * 2 + 1;
		end;

		t := q[s];
		q[s] := q[i];
		q[i] := t;

		i := s;
	end;
	u[r.x] := true;
	heappop := r;
end;

