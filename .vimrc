set number
set directory=~/*
set clipboard=unnamed,autoselect
set autoindent
set laststatus=2

inoremap { {}<LEFT>

" 隣接した{}で改行したらインデント
function! IndentBraces()
    let nowletter = getline(".")[col(".")-1]    " 今いるカーソルの文字
    let beforeletter = getline(".")[col(".")-2] " 1つ前の文字

    " カーソルの位置の括弧が隣接している場合
    if nowletter == "}" && beforeletter == "{"
        return "\n\n\<UP>\t"
    else
        return "\n"
    endif
endfunction
" Enterに割り当て
inoremap <silent> <expr> <CR> IndentBraces()
