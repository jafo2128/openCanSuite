/* Copyright Sebastian Haas <sebastian@sebastianhaas.info>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#include <MainWindow.h>

MainWindow::MainWindow()
{
    this->setupUi(this);

    QObject::connect(actionConnect, SIGNAL(triggered()), this, SLOT(onMenuConnect()));
}

/**
 * Open configured CAN interface
 */
void MainWindow::onMenuConnect()
{
    m_CanChannel = new QCanChannel("vcan0");

    QObject::connect(m_CanChannel, SIGNAL(canMessageReceived(const QCanMessage &)), this, SLOT(canMessageReceived(const QCanMessage &)));

    m_CanChannel->Start();
}

/**
 * Closed opened CAN interface
 */
void MainWindow::onMenuDisconnect()
{
}

void MainWindow::canMessageReceived(const QCanMessage & frame)
{
    qDebug("Received");
}

