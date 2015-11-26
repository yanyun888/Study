set nu
set autoindent
set cindent
set shiftwidth=4
set tabstop=4
set cul "高亮所在行
set matchtime=1

set hlsearch "搜索高亮
set incsearch
set ignorecase
set confirm
set nocompatible

set backspace=2
set wildmenu
set autochdir
"color desert     " 设置背景主题  
color ron     " 设置背景主题  
"color torte     " 设置背景主题  
set guifont=Courier_New:h16:cANSI   " 设置字体  

set scrolloff=3     "光标移动到buffer的顶部和底部时保持3行距离

set laststatus=2    " 启动显示状态行(1),总是显示状态行(2)  
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}   "状态行显示的内容  
set cmdheight=2

filetype on
"filetype plugin on
filetype indent on

set completeopt=longest,menu

"Taglist
let Tlist_File_Fold_Auto_Close=1
let Tlist_Close_On_Select=1
let Tlist_Exit_OnlyWindow=0
let Tlist_Use_SingleClick=1
let Tlist_Auto_Open=0


"新建.c,.h,.sh,.java文件，自动插入文件头 
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.rb,*.java,*.py exec ":call SetTitle()" 
func SetTitle() 
	"如果文件类型为.sh文件 
	if &filetype == 'sh' 
		call setline(1,"\#!/bin/bash") 
		call append(line("."), "") 
    elseif &filetype == 'python'
        call setline(1,"#!/usr/bin/env python")
        call append(line("."),"# coding=utf-8")
	    call append(line(".")+1, "") 

    elseif &filetype == 'ruby'
        call setline(1,"#!/usr/bin/env ruby")
        call append(line("."),"# encoding: utf-8")
	    call append(line(".")+1, "")

"    elseif &filetype == 'mkd'
"        call setline(1,"<head><meta charset=\"UTF-8\"></head>")
	else 
		call setline(1, "/*File Name: " .expand("%")) 
		call append(line("."), "**Author: ") 
		call append(line(".")+1, "**Version: ") 
		call append(line(".")+2, "**Created Time: ".strftime("%y/%m/%d-%H:%M")."  */") 
		call append(line(".")+3, " ") 
		call append(line(".")+4, " ") 
	endif
	if expand("%:e") == 'cpp'
		call append(line(".")+5, "#include<iostream>")
		call append(line(".")+6, "using namespace std;")
		call append(line(".")+7, "")
	endif
	if &filetype == 'c'
		call append(line(".")+5, "#include<stdio.h>")
		call append(line(".")+6, "#include<stdlib.h>")
		call append(line(".")+7, "")
		call append(line(".")+8, "")
	endif
	if expand("%:e") == 'h'
		call append(line(".")+5, "#ifndef _".toupper(expand("%:r"))."_H")
		call append(line(".")+6, "#define _".toupper(expand("%:r"))."_H")
		call append(line(".")+7, "#endif")
	endif
	if &filetype == 'java'
		call append(line(".")+5,"public class ".expand("%:r"))
		call append(line(".")+6,"")
	endif
endfunc 
autocmd BufNewFile * normal G

"自动补全
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
:inoremap ( ()<ESC>i
":inoremap < <><ESC>i
:inoremap { {<CR>}<ESC>O
:inoremap [ []<ESC>i

"快捷键

nmap <silent><F3> :NERDTreeToggle<CR>
imap <silent><F3> <ESC> :NERDTreeToggle<CR>
nmap <F4> :w<CR>
imap <F4> <ESC> :w<CR>
nmap <F5> :call CompileRunGcc()<CR>
"imap <F5> <ESC> :call CompileRunGcc<CR>
nmap <F8> :call Rungdb()<CR>
nmap <silent><F9> :TlistOpen<RETURN>
imap <silent><F9> <ESC>:TlistOpen<RETURN>
nmap <silent><F12> :g/^\s*$/d<CR>

func! CompileRunGcc()
	exec "w"
	if &filetype == 'c'
		exec "!cc % -o %<.out"
		exec "!time ./%<.out"
	elseif &filetype == 'cpp'
		exec "!g++ % -o %<"
		exec "!time ./%<"
	elseif &filetype == 'java' 
		exec "!javac %" 
		exec "!time java %<"
	elseif &filetype == 'sh'
		:!time bash %
	elseif &filetype == 'python'
		exec "!time python2.7 %"
    elseif &filetype == 'html'
        exec "!firefox % &"
    elseif &filetype == 'go'
"        exec "!go build %<"
        exec "!time go run %"
    elseif &filetype == 'mkd'
        exec "!~/.vim/markdown.pl % > %.html &"
        exec "!firefox %.html &"
	endif
endfunc

func! Rungdb()
	exec "w"
	exec "!g++ % -g -o %<.out"
	exec "!gdb ./%<.out"
endfunc

"autocmd
autocmd vimenter * if !argc() | NERDTree | endif
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | endif
"autocmd InsertLeave * normal mZ
"autocmd InsertEnter * se cul    " 用浅色高亮当前行




""""""""""""""""""""""""""
