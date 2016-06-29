program p291;
{
	@JUDGE_ID:  20044WC 291 PASCAL "DFS"
}
var
	p : array[0..5,0..5] of longint;
	s : string;
procedure dfs(f,t,l : longint);
var
	i  : longint;
begin
	s := s + chr(t+48);
	if l = 8 then begin writeln(s); delete(s, length(s), 1); exit; end;
	p[f,t] := 1;
	p[t,f] := 1;
	for i := 1 to 5 do begin
		if p[t, i] < 0 then dfs(t,i,l+1);
	end;
	p[f,t] := -1;
	p[t,f] := -1;
	delete(s, length(s), 1);
end;
begin
	p[1,2] := -1;
	p[1,3] := -1;
	p[1,5] := -1;

	p[2,1] := -1;
	p[2,3] := -1;
	p[2,5] := -1;

	p[3,1] := -1;
	p[3,2] := -1;
	p[3,4] := -1;
	p[3,5] := -1;

	p[4,3] := -1;
	p[4,5] := -1;

	p[5,1] := -1;
	p[5,2] := -1;
	p[5,3] := -1;
	p[5,4] := -1;
	dfs(0,1,0);
end.
