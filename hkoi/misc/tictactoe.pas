program minimax;
label hell;
type 
	ret = record
		max : longint;
		opt : longint;
	end;
var
	i,j,k : longint;
	w : array[1..3,1..3] of longint; { row, col }
	t : ret;
	userresult:longint;
function checkstate : boolean;
begin
	checkstate := false;
	if (w[1,1] = w[1,2]) and (w[1,1] = w[1,3]) and (w[1,1] > 0) then checkstate := true;
	if (w[2,1] = w[2,2]) and (w[2,1] = w[2,3]) and (w[2,1] > 0) then checkstate := true;
	if (w[3,1] = w[3,2]) and (w[3,1] = w[3,3]) and (w[3,1] > 0) then checkstate := true;

	if (w[1,1] = w[2,1]) and (w[1,1] = w[3,1]) and (w[1,1] > 0) then checkstate := true;
	if (w[1,2] = w[2,2]) and (w[1,2] = w[3,2]) and (w[1,2] > 0) then checkstate := true;
	if (w[1,3] = w[2,3]) and (w[1,3] = w[3,3]) and (w[1,3] > 0) then checkstate := true;

	if (w[1,1] = w[2,2]) and (w[2,2] = w[3,3]) and (w[2,2] > 0) then checkstate := true;
	if (w[3,1] = w[2,2]) and (w[2,2] = w[1,3]) and (w[2,2] > 0) then checkstate := true;
end;

function process(c,x : longint) : boolean;
var row,col,t,p : longint;
begin
	if c = -1 then exit;
	if c = -2 then exit;
	t := c mod 9;
	row := t div 3 + 1;
	col := t mod 3 + 1;

	if x >= 0 then begin { forward }
		if w[row,col] = 0 then begin
			w[row,col] := x+1;
			process := true;
		end else begin
			process := false;
		end;
	end else begin {  unprocess }
		w[row,col] := 0;
		process := true;
	end;
end;

procedure dump;
var
	i,j : longint;
begin
	for i := 1 to 3 do begin
		for j := 1 to 3 do write(w[i,j],' ');
		write('        ');
		for j := 1 to 3 do write(i*3-3+j:2,' ');
		writeln;
	end;
end;

function f(m,l : longint) : ret;
var i,r,max,opt : longint;
	t : ret;
begin
	if checkstate then begin
		max := -1;
		goto hell;
	end;
	max := -99;
	for i := 0 to 8 do begin
		if not process(i, m) then continue;
		t := f((m+1) mod 2, l+1); { nega }
		process(i,-1);
		if (-t.max > max) then begin
			max := -t.max;
			opt := i;
		end;
		if max = 1 then break;
	end;
	if max = -99 then begin
		max := 0;
		opt := -1;
	end;
	hell:
	f.max := max;
	f.opt := opt;
end;

begin
	process(0,1);
	while true do begin
		dump;
		writeln('chose a move (see above);');
		readln(k);
		while not process(k-1,0) do begin
			if k = -1 then exit;
			writeln('invalid move. again...');
			readln(k);
		end;
		t := f(1,0);
		if t.opt = -1 then begin
			if t.max = 1 then userresult := 1;
			if t.max = 0 then userresult := 0;
			break;
		end;
		process(t.opt, 1);
		if checkstate then begin
			userresult := -1;
			break;
		end;
	end;
	dump;
	if userresult = 1 then writeln('You win');
	if userresult = -1 then writeln('You lose');
	if userresult = 0 then writeln('Draw');
end.

