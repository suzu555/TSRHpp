// TSRH.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h" //高速化用と言われたが本当のヘッダ
#include "TSRH.h" //こっちは何も書かないのかヘッダ

#define MAX_LOADSTRING 100 //ワードの長さ、タイトルらしいね


// グローバル変数: //スコープを超えると楽なのを此処に書く
HINSTANCE hInst;                                // 現在のインターフェイス //インスタンスは色々使えるんじゃなったっけ
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト //タイトルは此処に置いて置かないと何だっけ？
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名 //クラス名も此処に置かないと何だっけ？

// このコード モジュールに含まれる関数の宣言を転送します: //初期化しといて定義
ATOM                MyRegisterClass(HINSTANCE hInstance); //クラスのウインドウズへの登録でしないとなんだっけ？
BOOL                InitInstance(HINSTANCE, int); //初期化か？
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); //コールバックメインの
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM); //アバウトのコールバック

////////////////////////////////////////////////////////自作関数//////////////////////////////////////////////////////
int aaa(void);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //メインループ関数の定義とインスタンスの送入
                     _In_opt_ HINSTANCE hPrevInstance, //なんだっけ？
                     _In_ LPWSTR    lpCmdLine, //コマンドライン実行の引数
                     _In_ int       nCmdShow) //なんだっけ？
{
    UNREFERENCED_PARAMETER(hPrevInstance); //定義、なんかの
    UNREFERENCED_PARAMETER(lpCmdLine); //定義、なんかの

    // TODO: ここにコードを挿入してください。




    // グローバル文字列を初期化する //何かを初期化するはず
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); //まあ、ウインドウに埋め込む文字をインスタンスに挿入 
    LoadStringW(hInstance, IDC_TSRH, szWindowClass, MAX_LOADSTRING); //まあ、ウインドウのクラスきっとウインドウズに登録をインスタンスに挿入
    MyRegisterClass(hInstance); //ウインドウズに登録

    // アプリケーション初期化の実行: //オーバーロードしたのを実行してるね、中身を追うように
    if (!InitInstance (hInstance, nCmdShow)) //インスタンスのオーバーロードを探せ
    {
        return FALSE; //しくったらFaLSE=0を返す
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TSRH)); //何をするんだっけ？加速だっけＳＳＥだっけ

    MSG msg; //メッセージを受け取るのを初期化

    // メイン メッセージ ループ:
    while (GetMessage(&msg, nullptr, 0, 0)) //メインループは此処
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) //メッセージ解析
        {
            TranslateMessage(&msg); //メッセージを受けとり、停止とか
            DispatchMessage(&msg); // メッセージを受け取ったので停止を解除
        }
    }

    return (int) msg.wParam; //次のループに返す、デスクトップのループだっけ？
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TSRH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TSRH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // グローバル変数にインスタンス ハンドルを格納する

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウを描画する
//  WM_DESTROY  - 中止メッセージを表示して戻る
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) //コールバック関数、結果を返すよ
{
	HWND hButtonWnd1; //ハンドル、ボタンの
	int aa; //なんかの変数
    switch (message) //大規模スイッチ、最後にデフォルトが入ってるし、deleteもあるよdelete:ね
    {
	//自作
	case WM_CREATE: //messageが此の数字だった場合defineね、これ
		hButtonWnd1 = CreateWindowEx( //ウインドウの作成、此れはボタンを作成している、ウインドウとダイアログね
			WS_EX_WINDOWEDGE, TEXT("BUTTON"),L"田代",
			BS_PUSHBUTTON | WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			0, 0, 100, 30, hWnd, (HMENU)1001, hInst, NULL);
		break; //breakeでcaseの所に逃げる

    case WM_COMMAND: //messageがコマンドだった場合のところ、defineで定義された数字ね、たしか、で、何か意識ある動作すると此のコマンドが呼ばれるの
        {
            int wmId = LOWORD(wParam); //wparamの数字で見た半分から下のビットだかを取り出し左辺に投げる
            // 選択されたメニューの解析:
            switch (wmId) //まあ、スイッチだ分れ
            {
			//自作
			case 1001:
				//ShellExecuteA(NULL, "open", "TASHIRO.wma", NULL, NULL, SW_SHOW);
				/*mciSendString(L"open TASHIRO.wma alias sound", NULL,
					0, NULL);
				*/
				/*mciSendString(L"play sound notify", NULL,
					0, NULL);
				*/
				//ShellExecuteA(NULL, "open", "https://www.google.com/search?q=片翼の田代", NULL, NULL, SW_SHOW);
				aa = aaa(); //自作関数の呼び出し
				break; //breakでコマンドの所に逃げる

            case IDM_ABOUT: //頑張れスイッチだだ
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); //ダイアログボックスの作成
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default: //default動作と上からのラベル追いを此処で受ける。
                return DefWindowProc(hWnd, message, wParam, lParam); //リターンする、分って。
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: HDC を使用する描画コードをここに追加してください...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// バージョン情報ボックスのメッセージ ハンドラーです。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int aaa()
{

	//文字
	TCHAR strBuffer[100];
	wsprintf(strBuffer, L"Listening on address: n");
	MessageBox(NULL, strBuffer, L"1", MB_OK);

	return true;
 }