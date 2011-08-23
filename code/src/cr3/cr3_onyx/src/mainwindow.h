#ifndef OnyxMainWindow_H
#define OnyxMainWindow_H

#include <QtGui/QMainWindow>
#include <QImage>

#include "cr3widget.h"

#include "onyx/ui/status_bar.h"
#include "onyx/ui/system_actions.h"
#include "onyx/ui/reading_tools_actions.h"
#include "onyx/ui/font_actions.h"
#include "onyx/ui/font_family_actions.h"
#include "onyx/ui/reading_style_actions.h"
#include "onyx/ui/zoom_setting_actions.h"

class QKeyEvent;

class OnyxMainWindow : public QMainWindow, public PropsChangeCallback
{
    Q_OBJECT

  public:
    virtual void onPropsChange( PropsRef props );
    OnyxMainWindow(QWidget *parent = 0);
    ~OnyxMainWindow();

  public slots:
    void on_actionFindText_triggered();

  protected:
    virtual void showEvent ( QShowEvent * event );
    virtual void focusInEvent ( QFocusEvent * event );
    virtual void closeEvent ( QCloseEvent * event );
    virtual void keyPressEvent(QKeyEvent *ke);
    virtual void keyReleaseEvent(QKeyEvent *ke);

  private slots:
    void showContextMenu();
    void onProgressClicked(const int, const int);
    bool addBookmark();
    void updateScreen();

  private:
    void toggleProperty( const char * name );
    bool isFullScreenByWidgetSize();
    void processToolActions();
    void showClock();
    void gotoPage();
    void showTableOfContents();

    void showAllBookmarks();
    void bookmarkModel(QStandardItemModel & model,
                       QModelIndex & selected);
    QStandardItem * searchParent(const int index,
                                 std::vector<int> & entries,
                                 std::vector<QStandardItem *> & ptrs,
                                 QStandardItemModel &model);

    void updateReadingStyleActions();
    void updateToolActions();
    bool updateActions();
    const QFont & currentFont();

    CR3View *view_;
    ui::StatusBar *status_bar_;
    QString file_name_to_open_;

    QFont select_font_;

    ui::SystemActions system_actions_;
    ui::ReadingToolsActions reading_tool_actions_;
    ui::ZoomSettingActions zoom_setting_actions_;
    ui::FontFamilyActions font_family_actions_;
    ui::FontActions font_actions_;
    ui::ReadingStyleActions reading_style_actions_;

    PropsRef props_ref_;
};

#endif // OnyxMainWindow_H
