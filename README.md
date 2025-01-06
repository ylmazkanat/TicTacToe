# Tic-Tac-Toe Oyunu

Bu depo, C dilinde yazılmış basit bir Tic-Tac-Toe (XOX) oyunu içerir. Oyun, iki oyuncunun sırayla hamle yaparak 3x3'lük bir tabloda üçlü bir sıra oluşturmayı amaçladığı klasik bir oyundur.

## İçindekiler

- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Kod Açıklamaları](#kod-açıklamaları)


## Kurulum

1. Depoyu klonlayın:

   ```bash
   git clone https://github.com/ylmazkanat/TicTacToe.git
   ```

2. Kaynak kodu derleyin:

   ```bash
   gcc main.c -o tictactoe
   ```

3. Oyunu çalıştırın:

   ```bash
   ./tictactoe
   ```

## Kullanım

- Program başlatıldığında, oyuncular sırayla hamle yapar.
- Oyuncular, 1 ile 9 arasında bir sayı girerek tahtadaki konumlarını seçerler.
- Oyun, bir oyuncu üçlü bir sıra oluşturduğunda veya tüm hücreler dolduğunda sona erer.

## Kod Açıklamaları

Kod, temel olarak aşağıdaki işlevleri içerir:

- **Tahta Yapısı ve Başlatma**: Oyun tahtası, 3x3'lük bir matris olarak temsil edilir ve başlangıçta boş olarak ayarlanır.

  ```c
  char board[3][3];
  void initializeBoard() {
      for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
              board[i][j] = ' ';
          }
      }
  }
  ```

- **Tahtayı Görüntüleme**: Mevcut oyun tahtası, oyuncuların hamlelerini görmeleri için ekrana yazdırılır.

  ```c
  void printBoard() {
      printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
      printf("---|---|---\n");
      printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
      printf("---|---|---\n");
      printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
  }
  ```

- **Hamle Yapma**: Oyuncuların girdilerine göre tahtada ilgili konum güncellenir.

  ```c
  int makeMove(int player, int position) {
      char mark = (player == 1) ? 'X' : 'O';
      int row = (position - 1) / 3;
      int col = (position - 1) % 3;
      if (board[row][col] == ' ') {
          board[row][col] = mark;
          return 1;
      }
      return 0;
  }
  ```

- **Kazananı Kontrol Etme**: Oyunun kazanılıp kazanılmadığını kontrol eden işlev.

  ```c
  int checkWin() {
      // Satırları kontrol et
      for (int i = 0; i < 3; i++) {
          if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
              return 1;
      }
      // Sütunları kontrol et
      for (int i = 0; i < 3; i++) {
          if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
              return 1;
      }
      // Çaprazları kontrol et
      if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
          return 1;
      if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
          return 1;
      return 0;
  }
  ```



