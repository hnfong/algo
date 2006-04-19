program p10111;
const debug = true;
var
	i,j,k,n : longint;
	e,f : longint;
	w : array[1..4,1..4] of char;
	tmpr,tmpc : longint;
	c : char;
	numx,numo : longint;
function checkwin : char;
var i,j : longint;
begin
	for i := 1 to 4 do begin
		if (w[i,1] = w[i,2])
		and(w[i,1] = w[i,3])
		and(w[i,1] = w[i,4]) then begin
			checkwin := w[i,1];
			exit;
		end;
		
		if (w[1,i] = w[2,i])
		and(w[1,i] = w[3,i])
		and(w[1,i] = w[4,i]) then begin
			checkwin := w[1,i];
			exit;
		end;
	end;
	if (w[1,1] = w[2,2])
	and(w[1,1] = w[3,3])
	and(w[1,1] = w[4,4]) then begin
		checkwin := w[1,1];
		exit;
	end;
	
	if (w[1,4] = w[2,3])
	and(w[1,4] = w[3,2])
	and(w[1,4] = w[4,1]) then begin
		checkwin := w[1,4];
		exit;
	end;
	checkwin := '.';
end;
procedure dump;
var i,j : longint;
begin
	for i := 1 to 4 do begin
		for j := 1 to 4 do write(w[i,j]);
		writeln;
	end;
end;

function negamax(a:char) : char;
label hell;
var
	b : char;
	i,j,k : longint;
	o : char;
	best : char;
	br,bc : longint;
	full : boolean;
begin
	o := checkwin;
	if o <> '.' then begin
		negamax := o;
		exit;
	end;

	if a='o' then b:='x' else b:='o';
	best := b; { assuming we lose! }
	full := true;
	for i := 1 to 4 do begin
		for j := 1 to 4 do begin
			if w[i,j] = '.' then begin
				full := false;
				w[i,j] := a;
				o := negamax(b);
				w[i,j] := '.';
				if (o = '.') then begin
					br := i;
					bc := j;
					best := '.';
				end;
				if (o = a) then begin
					br := i;
					bc := j;
					best := o;
					goto hell;
				end;
			end;
		end;
	end;
	hell:
	if full then best := '.';
	tmpr := br;
	tmpc := bc;
	negamax := best;
end;

begin
	while true do begin
		numx := 0; numo := 0;
		readln(c);
		if c = '$' then break;
		for i := 1 to 4 do begin
			for j := 1 to 4 do begin
				read(w[i,j]);
				if w[i,j] = 'x' then inc(numx);
				if w[i,j] = 'o' then inc(numo);
			end; readln;
		end;
		if (numx = 2) then begin
			writeln('#####');
			continue;
		end;
		if (negamax('x') = 'x') then begin
			writeln('(',tmpr-1,',',tmpc-1,')');
		end else begin
			writeln('#####');
		end;
	end;
end.

