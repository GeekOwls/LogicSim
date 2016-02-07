#include "gates.h"

// Qt includes

#include <QDebug>
#include <QPainter>

namespace Logicsim
{

// ===================== AndGate ===================

AndGate::AndGate()
    :Gate(Component::AndGate)
{
    setMetaTypeId(qRegisterMetaType<AndGate>("AndGate"));
}

AndGate::AndGate(const AndGate &g)
    : Gate(g.componentType())
{
}

QRectF AndGate::boundingRect() const
{
    return Component::boundingRect();
}

void AndGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawLine(0,0,0,50);
    painter->drawLine(0,0,20,0);
    painter->drawLine(0,50,20,50);
    painter->drawArc(QRect(0,0,40,50), -1400, 3000);
}

void AndGate::calcOutput()
{
    bool out = true;
    foreach (Node * n, inputList())
    {
        out &= n->value();
    }

    outputNode()->setValue(out);
}

QString AndGate::imageUrl() const
{
    return QString(":/gates/and");
}

// ===================== OrGate ===================


OrGate::OrGate()
    : Gate(Component::OrGate)
{
    setMetaTypeId(qRegisterMetaType<OrGate>("OrGate"));
}

OrGate::OrGate(const OrGate &g)
    : Gate(g.componentType())
{
}

void OrGate::calcOutput()
{
    bool out = false;
    foreach (Node * n, inputList())
    {
        out |= n->value();
    }

    outputNode()->setValue(out);
}

QString OrGate::imageUrl() const
{
    return QString(":/gates/or");
}

QRectF OrGate::boundingRect() const
{
    return Component::boundingRect();
}

void OrGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawArc(QRect(-22,-5,25,60), -800 , 1500);
    painter->drawArc(QRect(-30,-2,70,50), -1600, 1500);
    painter->drawArc(QRect(-30, 4,70,50),  100 , 1500);
}



// ===================== NotGate ===================

NotGate::NotGate()
    : Gate(Component::NotGate)
{
    setMaxInput(1);
    setMetaTypeId(qRegisterMetaType<NotGate>("NotGate"));
}

NotGate::NotGate(const NotGate &g)
    : Gate(g.componentType())
{
}

void NotGate::calcOutput()
{
    bool out = inputList()[0]->value();
    outputNode()->setValue(!out);
}

QString NotGate::imageUrl() const
{
    return QString(":/gates/not");
}

QRectF NotGate::boundingRect() const
{
    return Component::boundingRect();
}

void NotGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawLine(0,0,0,50);
    painter->drawLine(0,0,35,27);
    painter->drawLine(0,50,35,27);
    painter->drawEllipse(35,25,5,5);
}

// ===================== NandGate ===================

NandGate::NandGate()
    : Gate(Component::NandGate)
{
    setMetaTypeId(qRegisterMetaType<NandGate>("NandGate"));
}

NandGate::NandGate(const NandGate &g)
    : Gate(g.componentType())
{
}

void NandGate::calcOutput()
{
    bool out = true;
    foreach (Node * n, inputList())
    {
        out &= n->value();

    }

    outputNode()->setValue(!out);
}

QString NandGate::imageUrl() const
{
    return QString(":/gates/nand");
}


void NandGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawLine(0,0,0,50);
    painter->drawLine(0,0,17,0);
    painter->drawLine(0,50,17,50);
    painter->drawArc(QRect(-4,0,40,50), -1400, 3000);
    painter->drawEllipse(35,25,5,5);


}

// ===================== NorGate ===================

NorGate::NorGate()
    : Gate(Component::NorGate)
{
    setMetaTypeId(qRegisterMetaType<NorGate>("NorGate"));
}

NorGate::NorGate(const NorGate &g)
    : Gate(g.componentType())
{
}

void NorGate::calcOutput()
{
    bool out = false;
    foreach (Node * n, inputList())
    {
        out |= n->value();

    }

    outputNode()->setValue(!out);
}

QString NorGate::imageUrl() const
{
    return QString(":/gates/nor");
}

void NorGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawArc(QRect(-22,-5,25,60), -800, 1500);
    painter->drawArc(QRect(-23,-2,60,50), -1700, 1500);
    painter->drawArc(QRect(-23,4,60,50),  200, 1500);
    painter->drawEllipse(36,24,5,5);
}

// ===================== XorGate ===================

XorGate::XorGate()
    : Gate(Component::XorGate)
{
    setMetaTypeId(qRegisterMetaType<XorGate>("XorGate"));
}

XorGate::XorGate(const XorGate &g)
    : Gate(g.componentType())
{
}

void XorGate::calcOutput()
{
    bool out = inputList()[0]->value();
    outputNode()->setValue(out);
    int i ;
    for ( i = 1 ; i< inputList().size() ; i++);
    {
        if  ( inputList()[i]->value() == out )
            out = 0 ;
        else
            out = 1 ;
    }
    outputNode()->setValue(out);
}

QString XorGate::imageUrl() const
{
    return QString(":/gates/xor");
}

void XorGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawArc(QRect(-18,-5,25,60), -800, 1500);
    painter->drawArc(QRect(-23,-5,25,60), -750, 1350);
    painter->drawArc(QRect(-19,-2,60,50), -1700, 1600);
    painter->drawArc(QRect(-19,4,60,50),  200, 1500);

}

// ===================== XnorGate ===================

XnorGate::XnorGate()
    : Gate(Component::XnorGate)
{
    setMetaTypeId(qRegisterMetaType<XnorGate>("XnorGate"));
}

XnorGate::XnorGate(const XnorGate &g)
    : Gate(g.componentType())
{
}

void XnorGate::calcOutput()
{
    bool out = inputList()[0]->value();
    outputNode()->setValue(out);
    int i ;
    for ( i = 1 ; i< inputList().size() ; i++);
    {
        if  ( inputList()[i]->value() == out )
            out = 0 ;
        else
            out = 1 ;
    }
    outputNode()->setValue(!out);
}

QString XnorGate::imageUrl() const
{
    return QString(":/gates/xnor");
}

void XnorGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawArc(QRect(-18,-5,25,60), -800, 1500);
    painter->drawArc(QRect(-23,-5,25,60), -750, 1350);
    painter->drawArc(QRect(-24,-2,60,50), -1550, 1400);
    painter->drawArc(QRect(-24,4,60,50),  200, 1300);

    painter->drawEllipse(36,24,5,5);
}

} // namespace Logicsim
