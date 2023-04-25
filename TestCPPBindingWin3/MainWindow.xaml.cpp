// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include "Order.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
#include "Order.h"
namespace winrt::TestCPPBindingWin3::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}


void winrt::TestCPPBindingWin3::implementation::MainWindow::StackPanel_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    Windows::Foundation::Collections::IObservableVector<TestCPPBindingWin3::Order> m_Orders{ winrt::single_threaded_observable_vector<TestCPPBindingWin3::Order>() };

    for (int i = 0; i < 5; i++)
    {
        TestCPPBindingWin3::Order order = make<winrt::TestCPPBindingWin3::implementation::Order>();
        order.Amount(L"5.00");

        m_Orders.Append(order);
    }

    m_ListViewTest().ItemsSource(m_Orders);
}
