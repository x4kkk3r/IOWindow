/*
	MIT License

	Copyright (c) 2020 x4kkk3r

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef _IO_WIN32_WINDOW_HANDLE
#define _IO_WIN32_WINDOW_HANDLE

#ifdef _WIN32
#include <Windows.h>
#include <string>

class IOWin32WindowHandle
{
public:
	IOWin32WindowHandle() noexcept = default;
	IOWin32WindowHandle(const IOWin32WindowHandle &other) = delete;
	IOWin32WindowHandle(IOWin32WindowHandle &&other) = delete;
	~IOWin32WindowHandle() noexcept;

	bool Create
	(
		DWORD extendedStyle,
		std::string_view extendedClassName,
		std::string_view title,
		unsigned long width,
		unsigned long height,
		void *pParam
	) noexcept;
	void Destroy() noexcept;

	HWND GetWindowHandle() const noexcept;

	IOWin32WindowHandle& operator=(const IOWin32WindowHandle &other) = delete;
	IOWin32WindowHandle& operator=(IOWin32WindowHandle&& other) = delete;
private:
	HWND hWnd;

	static constexpr DWORD IO_WINDOW_STYLE = WS_OVERLAPPEDWINDOW;
	static constexpr DWORD IO_WINDOW_POSITION = CW_USEDEFAULT;
};
#endif

#endif