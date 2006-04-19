program sicx00;
type
	qtype = record
		x, y, d : longint;
	end;
var
	q : array[1..1000] of qtype;
	i,j,k : longint;
	n : longint;
	m : array[0..31,0..31] of char; { row, col }
	sm : array[0..31,0..31] of integer;
	cm : array[0..31,0..31] of integer;
	qh,qt : longint;
	qv : qtype;
	v : array[0..31,0..31] of boolean;
	siloc : qtype;
procedure dump;
var i ,j,k : longint;
begin
	exit;
	for i := 1 to n do begin
		for j := 1 to n do begin
			write(m[i,j]:3);
		end;
		writeln;
	end;
	writeln;
	for i := 1 to n do begin
		for j := 1 to n do begin
			write(sm[i,j]:3);
		end;
		writeln;
	end;
	writeln;
	for i := 1 to n do begin
		for j := 1 to n do begin
			write(cm[i,j]:3);
		end;
		writeln;
	end;
end;

procedure enq(x,y,who,d : longint);
begin
	if (x = 0) or (y=0) or (x > n) or (y > n) or (v[x,y]) or (m[x,y] = '0') then exit;
	if (who = 1) and (sm[x,y] = -1) then sm[x,y] := d;
	if (who = 2) and (cm[x,y] = -1) then cm[x,y] := d;
	v[x,y] := true;
	inc(qt);
	q[qt].x := x;
	q[qt].y := y;
	q[qt].d := d;
end;

function deq : qtype;
begin
	inc(qh);
	deq.x := q[qh].x;
	deq.y := q[qh].y;
	deq.d := q[qh].d;
end;

begin
	qh := 0;
	qt := 0;
	fillchar(m, sizeof(m), 0);
	fillchar(sm, sizeof(sm), 0);
	fillchar(cm, sizeof(cm), 0);
	for i := 0 to 31 do begin for j := 0 to 31 do begin sm[i,j] := -1; end; end;
	for i := 0 to 31 do begin for j := 0 to 31 do begin cm[i,j] := -1; end; end;
	fillchar(q, sizeof(q), 0);
	fillchar(v, sizeof(v), 0);

	assign(input, 'sicx00.in');
	reset(input);
	assign(output, 'sicx00.out');
	rewrite(output);
	
	readln(n);
	for i := 1 to n do begin
		for j := 1 to n do begin
			read(m[i,j]);
			if m[i,j] = 'C' then enq(i,j, 2, 0);
			if m[i,j] = 'S' then begin
				siloc.x := i;
				siloc.y := j;
			end;
		end;
		readln;
	end;
	{ cx bfs }
	while (qt <> qh) do begin
		qv := deq;
		enq(qv.x+1, qv.y, 2, qv.d+1);
		enq(qv.x-1, qv.y, 2, qv.d+1);
		enq(qv.x, qv.y+1, 2, qv.d+1);
		enq(qv.x, qv.y-1, 2, qv.d+1);
	end;
	
	qt := 0;
	qh := 0;
	fillchar(v, sizeof(v), 0);

	enq(siloc.x, siloc.y, 1, 0);
	{ si bfs }
	while (qt <> qh) do begin
		qv := deq;
		enq(qv.x+1, qv.y, 1, qv.d+1);
		enq(qv.x-1, qv.y, 1, qv.d+1);
		enq(qv.x, qv.y+1, 1, qv.d+1);
		enq(qv.x, qv.y-1, 1, qv.d+1);
	end;
	
	k := -1;
	for i := 1 to n do begin
		for j := 1 to n do begin
			{check if it's < or <= }
			if (sm[i,j] < cm[i,j]) and (k < cm[i,j]) and (sm[i,j] >= 0) then begin
				k := cm[i,j];
			end;
		end;
	end;
	if (k < 0) then writeln('SI rulz.') else writeln('SI is eliminated after ',k,' minute(s).');
	dump;
	close(input);
	close(output);
end.

