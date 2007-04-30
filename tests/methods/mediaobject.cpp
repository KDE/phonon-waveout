addSignal("prefinishMarkReached(qint32)");
addSignal("tick(qint64)");
addSignal("hasVideoChanged(bool)");
addMethod("qint32", "transitionTime()");
addMethod("qint64", "remainingTime()", true);
addSignal("metaDataChanged(const QMultiMap<QString, QString>&)");
addSignal("aboutToFinish()");
addSignal("stateChanged(Phonon::State, Phonon::State)");
addSignal("seekableChanged(bool)");
addSignal("totalTimeChanged(qint64)");
addSignal("finished()");
addMethod("", "setTransitionTime(qint32)");
addMethod("qint32", "prefinishMark()");
addSignal("bufferStatus(int)");
addMethod("", "setPrefinishMark(qint32)");
